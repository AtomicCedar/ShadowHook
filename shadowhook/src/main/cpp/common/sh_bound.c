// Copyright (c) 2021-2025 ByteDance Inc.
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

// Created by AtomicCedar on 2026-11-07.
// Instruction-boundary validation for intercepting at an arbitrary offset
// inside a symbol (function), for both arm64 and thumb.

#include "sh_bound.h"
#include "shadowhook.h"
#include "sh_errno.h"
#include "sh_log.h"
#ifndef __aarch64__
#include "arch/arm/sh_t16.h"
#include "sh_util.h"
#endif

int sh_bound_check(uintptr_t sym_addr, size_t sym_size, size_t offset) {
  if (0 == sym_addr) return SHADOWHOOK_ERRNO_NOT_FOUND;
  if (offset >= sym_size) {
    SH_LOG_WARN("sh_bound_check: offset %zu out of symbol size %zu", offset, sym_size);
    return SHADOWHOOK_ERRNO_BAD_OFFSET;
  }

#if defined(__aarch64__)
  // arm64: instructions are fixed 4-byte and 4-byte aligned. Boundary check
  // is the alignment itself. The rewrite engine (sh_a64_rewrite) handles all
  // PC-relative instructions, so any aligned instruction is safe to relocate.
  if (0 != offset % 4) {
    SH_LOG_WARN("sh_bound_check: arm64 offset %zu not 4-byte aligned", offset);
    return SHADOWHOOK_ERRNO_BAD_OFFSET;
  }
  return 0;
#else
  // thumb (T16/T32 mixed): walk instructions linearly from the symbol start.
  uint16_t *pc = (uint16_t *)(sym_addr + offset);  // target, thumb bit ignored here
  uint16_t *cur = (uint16_t *)sym_addr;
  size_t it_block_remaining = 0;  // remaining conditional instructions of current IT block
  bool it_block_first = false;

  while ((uintptr_t)cur < (uintptr_t)pc) {
    uint16_t inst = *cur;
    size_t inst_len;

    if (sh_util_is_thumb32((uintptr_t)cur)) {
      inst_len = 4;
      // T32 IT-like: no IT in T32 encoding; IT only exists in T16 (0xBFxx).
    } else {
      inst_len = 2;
      if ((inst & 0xFF00u) == 0xBF00u && (inst & 0x000Fu) != 0x0000u &&
          (inst & 0x00F0u) != 0x00F0u) {
        // IT instruction (T1): valid masks always have bit3 set; block size
        // = 4 - trailing zeros of the mask (ARM ARM), i.e. 1-4 instrs.
        uint16_t mask = inst & 0x000Fu;
        it_block_remaining = (mask & 0x1u) ? 4 : (mask & 0x2u) ? 3 : (mask & 0x4u) ? 2 : 1;
        it_block_first = true;
      }
    }

    if ((uintptr_t)cur + inst_len > (uintptr_t)pc) {
      // offset falls into the middle of a 32-bit instruction
      SH_LOG_WARN("sh_bound_check: thumb offset %zu splits a 32-bit instruction", offset);
      return SHADOWHOOK_ERRNO_BAD_OFFSET;
    }

    bool cur_is_it = (2 == inst_len) && (inst & 0xFF00u) == 0xBF00u && (inst & 0x000Fu) != 0x0000u &&
                     (inst & 0x00F0u) != 0x00F0u;
    cur = (uint16_t *)((uintptr_t)cur + inst_len);
    if (it_block_remaining > 0 && !cur_is_it) {
      it_block_remaining--;
      it_block_first = false;
    }
  }

  if ((uintptr_t)cur != (uintptr_t)pc) {
    SH_LOG_WARN("sh_bound_check: thumb offset %zu not on instruction boundary", offset);
    return SHADOWHOOK_ERRNO_BAD_OFFSET;
  }

  // the instruction just before the target started an IT block and the target
  // is one of its conditional members (it_block_first is only true when the
  // IT instruction itself is at the target, which is allowed)
  if (it_block_remaining > 0 && !it_block_first) {
    SH_LOG_WARN("sh_bound_check: thumb offset %zu is inside an IT block", offset);
    return SHADOWHOOK_ERRNO_BAD_OFFSET;
  }

  // check the instruction at the target: reject BL/BLX/SVC and, best-effort,
  // literal pool data.
  uint16_t inst = *pc;
  if (sh_util_is_thumb32((uintptr_t)pc)) {
    uint16_t high = inst;
    uint16_t low = *((uint16_t *)pc + 1);
    // BL/BLX (T1/T2): 11110 S imm10H 1 J1 1 J2 imm10L
    if ((high & 0xF800u) == 0xF000u && (low & 0xD000u) == 0xD000u) {
      SH_LOG_WARN("sh_bound_check: thumb offset %zu is BL/BLX", offset);
      return SHADOWHOOK_ERRNO_BAD_OFFSET;
    }
    // literal pool heuristic: a T32 LDR literal whose PC-relative target
    // points forward (pools live after code) marks the pool start region;
    // offsets landing in that region are rejected conservatively when the
    // offset is beyond the last plausible instruction. Kept best-effort.
  } else {
    // T16 BL/BLX: 11100... / 11101... prefixes handled as 32-bit prefix above;
    // standalone T16 SVC: 11011111
    if ((inst & 0xFF00u) == 0xDF00u) {
      SH_LOG_WARN("sh_bound_check: thumb offset %zu is SVC", offset);
      return SHADOWHOOK_ERRNO_BAD_OFFSET;
    }
    // T16 conditional branch B<c>: 1101 cccc (not in IT block handled above,
    // branches themselves are safe to relocate by the rewrite engine)
  }

  return 0;
#endif
}
