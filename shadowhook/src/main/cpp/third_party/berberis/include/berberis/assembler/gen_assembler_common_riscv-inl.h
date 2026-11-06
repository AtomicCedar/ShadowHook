constexpr void Add([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'0033}>(arg0, arg1, arg2);
}
constexpr void Addi([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'0013}>(arg0, arg1, arg2);
}
constexpr void And([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'7033}>(arg0, arg1, arg2);
}
constexpr void Andi([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'7013}>(arg0, arg1, arg2);
}
constexpr void Auipc([[maybe_unused]] Register arg0, [[maybe_unused]] UImmediate arg1) {
  EmitUTypeInstruction<uint32_t{0x0000'0017}>(arg0, arg1);
}
constexpr void Bcc([[maybe_unused]] Condition arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2, [[maybe_unused]] BImmediate arg3);
constexpr void Bcc([[maybe_unused]] Condition arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2, [[maybe_unused]] const Label& arg3);
constexpr void Beq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Beq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] BImmediate arg2) {
  EmitBTypeInstruction<uint32_t{0x0000'0063}>(arg0, arg1, arg2);
}
constexpr void Beqz([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Bge([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bge([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] BImmediate arg2) {
  EmitBTypeInstruction<uint32_t{0x0000'5063}>(arg0, arg1, arg2);
}
constexpr void Bgeu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bgeu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] BImmediate arg2) {
  EmitBTypeInstruction<uint32_t{0x0000'7063}>(arg0, arg1, arg2);
}
constexpr void Bgez([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Bgt([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bgtu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bgtz([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Ble([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bleu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Blez([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Blt([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Blt([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] BImmediate arg2) {
  EmitBTypeInstruction<uint32_t{0x0000'4063}>(arg0, arg1, arg2);
}
constexpr void Bltu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bltu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] BImmediate arg2) {
  EmitBTypeInstruction<uint32_t{0x0000'6063}>(arg0, arg1, arg2);
}
constexpr void Bltz([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Bne([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Label& arg2);
constexpr void Bne([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] BImmediate arg2) {
  EmitBTypeInstruction<uint32_t{0x0000'1063}>(arg0, arg1, arg2);
}
constexpr void Bnez([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Call([[maybe_unused]] const Label& arg0);
constexpr void Csrrc([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] CsrImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'7073}>(arg0, arg1, arg2);
}
constexpr void Csrrc([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] Register arg2) {
  EmitITypeInstruction<uint32_t{0x0000'3073}>(arg0, arg1, arg2);
}
constexpr void Csrrci([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] CsrImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'7073}>(arg0, arg1, arg2);
}
constexpr void Csrrs([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] CsrImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'6073}>(arg0, arg1, arg2);
}
constexpr void Csrrs([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] Register arg2) {
  EmitITypeInstruction<uint32_t{0x0000'2073}>(arg0, arg1, arg2);
}
constexpr void Csrrsi([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] CsrImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'6073}>(arg0, arg1, arg2);
}
constexpr void Csrrw([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] CsrImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'5073}>(arg0, arg1, arg2);
}
constexpr void Csrrw([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] Register arg2) {
  EmitITypeInstruction<uint32_t{0x0000'1073}>(arg0, arg1, arg2);
}
constexpr void Csrrwi([[maybe_unused]] Register arg0, [[maybe_unused]] Csr arg1, [[maybe_unused]] CsrImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'5073}>(arg0, arg1, arg2);
}
constexpr void Div([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'4033}>(arg0, arg1, arg2);
}
constexpr void Divu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'5033}>(arg0, arg1, arg2);
}
constexpr void FcvtDS([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0x4200'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtDS([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0x4200'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtDW([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd200'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtDW([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd200'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtDWu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd210'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtDWu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd210'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtSD([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0x4010'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtSD([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0x4010'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtSW([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd000'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtSW([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd000'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtSWu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd010'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtSWu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd010'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtWD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc200'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtWD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc200'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtWS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc000'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtWS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc000'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtWuD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc210'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtWuD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc210'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtWuS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc010'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtWuS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc010'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void Fld([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Fld([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'3007}>(arg0, arg1);
}
constexpr void Flw([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Flw([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'2007}>(arg0, arg1);
}
constexpr void Fsd([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Fsd([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Operand<Register, SImmediate>& arg1) {
  EmitSTypeInstruction<uint32_t{0x0000'3027}>(arg0, arg1);
}
constexpr void FsqrtD([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0x5a00'0053}>(arg0, arg1, arg2);
}

constexpr void FsqrtD([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0x5a00'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FsqrtS([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0x5800'0053}>(arg0, arg1, arg2);
}

constexpr void FsqrtS([[maybe_unused]] FpRegister arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0x5800'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void Fsw([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Fsw([[maybe_unused]] FpRegister arg0, [[maybe_unused]] const Operand<Register, SImmediate>& arg1) {
  EmitSTypeInstruction<uint32_t{0x0000'2027}>(arg0, arg1);
}
constexpr void J([[maybe_unused]] JImmediate arg0);
constexpr void Jal([[maybe_unused]] JImmediate arg0);
constexpr void Jal([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Jal([[maybe_unused]] Register arg0, [[maybe_unused]] JImmediate arg1) {
  EmitJTypeInstruction<uint32_t{0x0000'006f}>(arg0, arg1);
}
constexpr void Jalr([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'0067}>(arg0, arg1, arg2);
}
constexpr void Jalr([[maybe_unused]] Register arg0);
constexpr void Jalr([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'0067}>(arg0, arg1);
}
constexpr void Jr([[maybe_unused]] Register arg0);
constexpr void La([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lb([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lb([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'0003}>(arg0, arg1);
}
constexpr void Lbu([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lbu([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'4003}>(arg0, arg1);
}
constexpr void Lh([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lh([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'1003}>(arg0, arg1);
}
constexpr void Lhu([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lhu([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'5003}>(arg0, arg1);
}
constexpr void Li([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1);
template<typename ImmType>
auto Li([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Lui([[maybe_unused]] Register arg0, [[maybe_unused]] UImmediate arg1) {
  EmitUTypeInstruction<uint32_t{0x0000'0037}>(arg0, arg1);
}
constexpr void Lw([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lw([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'2003}>(arg0, arg1);
}
constexpr void Mul([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'0033}>(arg0, arg1, arg2);
}
constexpr void Mulh([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'1033}>(arg0, arg1, arg2);
}
constexpr void Mulhsu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'2033}>(arg0, arg1, arg2);
}
constexpr void Mulhu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'3033}>(arg0, arg1, arg2);
}
constexpr void Mv([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Neg([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Not([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Or([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'6033}>(arg0, arg1, arg2);
}
constexpr void Ori([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'6013}>(arg0, arg1, arg2);
}
constexpr void PrefetchI([[maybe_unused]] const Operand<Register, PImmediate>& arg0) {
  EmitPTypeInstruction<uint32_t{0x0000'6013}>(arg0);
}
constexpr void PrefetchR([[maybe_unused]] const Operand<Register, PImmediate>& arg0) {
  EmitPTypeInstruction<uint32_t{0x0010'6013}>(arg0);
}
constexpr void PrefetchW([[maybe_unused]] const Operand<Register, PImmediate>& arg0) {
  EmitPTypeInstruction<uint32_t{0x0030'6013}>(arg0);
}
constexpr void Rem([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'6033}>(arg0, arg1, arg2);
}
constexpr void Remu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'7033}>(arg0, arg1, arg2);
}
constexpr void Ret();
constexpr void Ror([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x6000'5033}>(arg0, arg1, arg2);
}
constexpr void Sb([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Sb([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, SImmediate>& arg1) {
  EmitSTypeInstruction<uint32_t{0x0000'0023}>(arg0, arg1);
}
constexpr void Seqz([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void SextB([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0x6040'1013}>(arg0, arg1);
}
constexpr void SextH([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0x6050'1013}>(arg0, arg1);
}
constexpr void Sgtz([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Sh([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Sh([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, SImmediate>& arg1) {
  EmitSTypeInstruction<uint32_t{0x0000'1023}>(arg0, arg1);
}
constexpr void Sh3add([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x2000'6033}>(arg0, arg1, arg2);
}
constexpr void Sll([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'1033}>(arg0, arg1, arg2);
}
constexpr void Slt([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'2033}>(arg0, arg1, arg2);
}
constexpr void Slti([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'2013}>(arg0, arg1, arg2);
}
constexpr void Sltiu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'3013}>(arg0, arg1, arg2);
}
constexpr void Sltu([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'3033}>(arg0, arg1, arg2);
}
constexpr void Sltz([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Snez([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Sra([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x4000'5033}>(arg0, arg1, arg2);
}
constexpr void Sraw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x4000'503b}>(arg0, arg1, arg2);
}
constexpr void Srl([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'5033}>(arg0, arg1, arg2);
}
constexpr void Srlw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'503b}>(arg0, arg1, arg2);
}
constexpr void Sub([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x4000'0033}>(arg0, arg1, arg2);
}
constexpr void Sw([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Sw([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, SImmediate>& arg1) {
  EmitSTypeInstruction<uint32_t{0x0000'2023}>(arg0, arg1);
}
constexpr void Tail([[maybe_unused]] const Label& arg0);
constexpr void Xor([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'4033}>(arg0, arg1, arg2);
}
constexpr void Xori([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'4013}>(arg0, arg1, arg2);
}
