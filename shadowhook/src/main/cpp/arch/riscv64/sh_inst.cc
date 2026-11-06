// Copyright (c) 2021-2026 ByteDance Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

// Created by Eirv (loveirv@outlook.com) on 2026-10-10.

#include "sh_inst.h"

#include <sys/mman.h>

#include <cstddef>

#include "berberis/assembler/rv64i.h"
#include "berberis/decoder/riscv64/decoder.h"
#include "sh_enter.h"
#include "sh_safe.h"
#include "sh_util.h"

extern "C" {
extern void shadowhook_interceptor_glue();
}

using namespace shadowhook;

class Assembler : public berberis::rv64i::Assembler {
 public:
  explicit Assembler(berberis::MachineCode *code) : berberis::rv64i::Assembler(code) {}

  static consteval uint32_t auipc(Register rd, int32_t imm) {
    return 0x17 | RegisterOperand<RdMarker, Register>{rd}.EncodeImmediate() | (imm << 12);
  }

  static consteval uint32_t ld(Register rd, Register rs1, int32_t imm) {
    return 0x3003 | RegisterOperand<RdMarker, Register>{rd}.EncodeImmediate() |
           RegisterOperand<Rs1Marker, Register>{rs1}.EncodeImmediate() | (imm << 20);
  }

  static consteval uint16_t c_jr(Register rs1) {
    return 0b10 | (0b1000 << 12) | (rs1.GetPhysicalIndex() << 7);
  }

  static consteval uint16_t c_ebreak() {
    return 0b10 | (0b1001 << 12);
  }
};

class RiscV64 {
 public:
  using Decoder = berberis::Decoder<RiscV64>;
  using Register = Assembler::Register;

  static size_t Relocate(const uint16_t *address, ssize_t size, void **relocated, size_t *relocated_size) {
    if (size & 1) {
      return 0;
    }

    berberis::MachineCode code;
    Assembler assembler(&code);

    RiscV64 relocator(assembler);
    Decoder decoder(&relocator);

    size_t overwrite_size = 0;

    while (size > 0) {
      if (!address[0]) [[unlikely]] {  // c.unimp * 1
        assembler.TwoByte(uint16_t{0});
        if (!address[1] && !address[2] && !address[3]) {  // c.unimp * 4
          break;
        }
        size -= 2;
        address += 1;
        overwrite_size += 2;
        continue;
      }
      relocator.SetPC(reinterpret_cast<uintptr_t>(address));
      auto count = decoder.Decode(address);
      if (auto state = relocator.GetState(); state == kSkipped) {
        if (count == 4) {
          assembler.TwoByte(address[0], address[1]);
        } else {
          assembler.TwoByte(address[0]);
        }
      } else if (state != kRelocated) {
        return 0;
      }
      size -= count;
      address += count / sizeof(uint16_t);
      overwrite_size += count;
    }

    relocator.JumpAddress(reinterpret_cast<uint64_t>(address));
    relocator.EmitAddresses();
    assembler.Finalize();

    auto backup = sh_safe_mmap(nullptr, code.install_size(), PROT_READ | PROT_WRITE | PROT_EXEC,
                               MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (backup == MAP_FAILED) abort();
    *relocated = backup;
    if (relocated_size) {
      *relocated_size = code.install_size();
    }

    berberis::RecoveryMap recovery_map;
    code.InstallUnsafe(static_cast<uint8_t *>(backup), &recovery_map);
    sh_util_clear_cache(reinterpret_cast<uintptr_t>(backup), code.install_size());

    return overwrite_size;
  }

  void Auipc(const typename Decoder::UpperImmArgs &args) {
    assembler_.Ld(Register{args.dst}, addresses_[GetPC() + args.imm]);
    SetNewState(kRelocated);
  }

  void CompareAndBranch(const typename Decoder::BranchArgs &args) {
    auto address = GetPC() + args.offset;
    auto &label = *assembler_.MakeLabel();
    auto &branch_label = *assembler_.MakeLabel();
    switch (args.opcode) {
      case Decoder::BranchOpcode::kBeq:
        if (args.src2 == 0) {
          assembler_.Beqz(Register{args.src1}, branch_label);
        } else {
          assembler_.Beq(Register{args.src1}, Register{args.src2}, branch_label);
        }
        break;
      case Decoder::BranchOpcode::kBne:
        if (args.src2 == 0) {
          assembler_.Bnez(Register{args.src1}, branch_label);
        } else {
          assembler_.Bne(Register{args.src1}, Register{args.src2}, branch_label);
        }
        break;
      case Decoder::BranchOpcode::kBlt:
        if (args.src2 == 0) {
          assembler_.Bltz(Register{args.src1}, branch_label);
        } else {
          assembler_.Blt(Register{args.src1}, Register{args.src2}, branch_label);
        }
        break;
      case Decoder::BranchOpcode::kBge:
        if (args.src2 == 0) {
          assembler_.Bgez(Register{args.src1}, branch_label);
        } else {
          assembler_.Bge(Register{args.src1}, Register{args.src2}, branch_label);
        }
        break;
      case Decoder::BranchOpcode::kBltu:
        assembler_.Bltu(Register{args.src1}, Register{args.src2}, branch_label);
        break;
      case Decoder::BranchOpcode::kBgeu:
        assembler_.Bgeu(Register{args.src1}, Register{args.src2}, branch_label);
        break;
      default:
        Undefined();
        return;
    }
    assembler_.Jal(Assembler::zero, label);
    assembler_.Bind(&branch_label);
    JumpAddress(address);
    assembler_.Bind(&label);
    SetNewState(kRelocated);
  }

  void JumpAndLink(const typename Decoder::JumpAndLinkArgs &args) {
    assembler_.Ld(Assembler::t3, addresses_[GetPC() + args.offset]);
    assembler_.Jalr(Register{args.dst}, Assembler::t3, 0);
    SetNewState(kRelocated);
  }

  void JumpAndLinkRegister(const typename Decoder::JumpAndLinkRegisterArgs &args) {
    if (args.dst == 0 /* zero */ && args.base == 1 /* ra */ && args.offset == 0) {
      returned_ = true;
    }
    Skip();
  }

  void Amo(const auto &) {
    Skip();
  }

  void Csr(const auto &) {
    Skip();
  }

  void Fcvt(const auto &) {
    Skip();
  }

  void Fma(const auto &) {
    Skip();
  }

  void Fence(const auto &) {
    Skip();
  }

  void FenceI(const auto &) {
    Skip();
  }

  void Load(const auto &) {
    Skip();
  }

  void Lui(const auto &) {
    Skip();
  }

  void Nop() {
    Skip();
  }

  void Op(auto &&) {
    Skip();
  }

  void OpSingleInput(const auto &) {
    Skip();
  }

  void OpFp(const auto &) {
    Skip();
  }

  void OpFpGpRegisterTargetNoRounding(const auto &) {
    Skip();
  }

  void OpFpGpRegisterTargetSingleInputNoRounding(const auto &) {
    Skip();
  }

  void OpFpNoRounding(const auto &) {
    Skip();
  }

  void FmvFloatToInteger(const auto &) {
    Skip();
  }

  void FmvIntegerToFloat(const auto &) {
    Skip();
  }

  void OpFpSingleInput(const auto &) {
    Skip();
  }

  void OpFpSingleInputNoRounding(const auto &) {
    Skip();
  }

  void OpImm(auto &&) {
    Skip();
  }

  void OpVector(const auto &) {
    Skip();
  }

  void Vsetivli(const auto &) {
    Skip();
  }

  void Vsetvl(const auto &) {
    Skip();
  }

  void Vsetvli(const auto &) {
    Skip();
  }

  void Store(const auto &) {
    Skip();
  }

  void System(const auto &) {
    Skip();
  }

  void Undefined() {
    if (returned_) {
      Skip();
    } else {
      SetNewState(kError);
    }
  }

 private:
  static constexpr uint8_t kNone = 0;
  static constexpr uint8_t kSkipped = 1;
  static constexpr uint8_t kRelocated = 2;
  static constexpr uint8_t kError = 3;

  Assembler &assembler_;
  std::map<uint64_t, Assembler::Label> addresses_{};
  uintptr_t pc_{};
  uint8_t state_{};
  bool returned_{};

  explicit RiscV64(Assembler &assembler) : assembler_(assembler) {}

  void SetPC(uintptr_t pc) {
    pc_ = pc;
  }

  [[nodiscard]] uintptr_t GetPC() const {
    return pc_;
  }

  void Skip() {
    SetNewState(kSkipped);
  }

  uint8_t GetState() {
    auto s = state_;
    state_ = kNone;
    return s;
  }

  void SetNewState(uint8_t state) {
    if (state_ == kNone || state_ == kSkipped) {
      state_ = state;
    } else {
      state_ = kError;
    }
  }

  void JumpAddress(uint64_t address) {
    assembler_.Ld(Assembler::t3, addresses_[address]);
    assembler_.Jr(Assembler::t3);
  }

  void EmitAddresses() {
    for (auto &p : addresses_) {
      assembler_.Bind(&p.second);
      assembler_.Emit64(p.first);
    }
  }
};

void AbsoluteJump(uintptr_t buf, uintptr_t target_addr) {
  *reinterpret_cast<uint32_t *>(buf) = Assembler::auipc(Assembler::t3, 0);
  *reinterpret_cast<uint32_t *>(buf + 4) = Assembler::ld(Assembler::t3, Assembler::t3, 10);
  *reinterpret_cast<uint16_t *>(buf + 8) = Assembler::c_jr(Assembler::t3);
  *reinterpret_cast<uintptr_t *>(buf + 10) = target_addr;
}

int sh_inst_hook(sh_inst_t *self, uintptr_t target_addr, sh_addr_info_t *addr_info, uintptr_t new_addr,
                 bool is_to_interceptor, sh_inst_set_orig_addr_t set_orig_addr, void *set_orig_addr_arg,
                 sh_recorder_trace_t *trace) {
  void *relocated = nullptr;
  size_t relocated_size = 0;
  auto overwrite_size =
      RiscV64::Relocate(reinterpret_cast<const uint16_t *>(target_addr), 18, &relocated, &relocated_size);
  if (overwrite_size == 20) {
    *reinterpret_cast<uint16_t *>(target_addr + 18) = Assembler::c_ebreak();
  }
  self->backup_len = overwrite_size;
  self->enter = reinterpret_cast<uintptr_t>(relocated);
  self->enter_len = relocated_size;
  if (set_orig_addr) set_orig_addr(reinterpret_cast<uintptr_t>(relocated), set_orig_addr_arg);
  memcpy(self->backup, reinterpret_cast<void *>(target_addr), overwrite_size);
  AbsoluteJump(target_addr, new_addr);
  sh_util_clear_cache(target_addr, overwrite_size);
  return 0;
}

int sh_inst_rehook(sh_inst_t *self, uintptr_t target_addr, sh_addr_info_t *addr_info, uintptr_t new_addr,
                   bool is_to_interceptor, sh_recorder_trace_t *trace) {
  abort();
}

int sh_inst_unhook(sh_inst_t *self, uintptr_t target_addr, uintptr_t load_bias) {
  abort();
}

void sh_inst_free_after_dlclose(sh_inst_t *self, uintptr_t target_addr) {
  abort();
}

void sh_inst_build_glue_launcher(void *buf, void *ctx) {
  abort();
}
