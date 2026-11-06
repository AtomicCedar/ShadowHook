constexpr void AddUW([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0800'003b}>(arg0, arg1, arg2);
}
constexpr void Addiw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] IImmediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'001b}>(arg0, arg1, arg2);
}
constexpr void Addw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'003b}>(arg0, arg1, arg2);
}
constexpr void Bexti([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift64Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x4800'5013}>(arg0, arg1, arg2);
}
constexpr void Divuw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'503b}>(arg0, arg1, arg2);
}
constexpr void Divw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'403b}>(arg0, arg1, arg2);
}
constexpr void FcvtDL([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd220'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtDL([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd220'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtDLu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd230'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtDLu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd230'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtLD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc220'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtLD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc220'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtLS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc020'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtLS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc020'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtLuD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc230'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtLuD([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc230'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtLuS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xc030'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtLuS([[maybe_unused]] Register arg0, [[maybe_unused]] FpRegister arg1) {
  EmitRTypeInstruction<uint32_t{0xc030'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtSL([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd020'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtSL([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd020'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void FcvtSLu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Rounding arg2) {
  EmitRTypeInstruction<uint32_t{0xd030'0053}>(arg0, arg1, arg2);
}

constexpr void FcvtSLu([[maybe_unused]] FpRegister arg0, [[maybe_unused]] Register arg1) {
  EmitRTypeInstruction<uint32_t{0xd030'0053}>(arg0, arg1, Rounding::kDyn);
}

constexpr void Ld([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Ld([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'3003}>(arg0, arg1);
}
constexpr void Li([[maybe_unused]] Register arg0, [[maybe_unused]] int64_t arg1);
template<typename ImmType>
auto Li([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int64_t) < sizeof(ImmType)> = delete;
constexpr void Lwu([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1);
constexpr void Lwu([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, IImmediate>& arg1) {
  EmitITypeInstruction<uint32_t{0x0000'6003}>(arg0, arg1);
}
constexpr void Mulw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'003b}>(arg0, arg1, arg2);
}
constexpr void Negw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Remuw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'703b}>(arg0, arg1, arg2);
}
constexpr void Remw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0200'603b}>(arg0, arg1, arg2);
}
constexpr void Rori([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift64Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x6000'5013}>(arg0, arg1, arg2);
}
constexpr void Roriw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift32Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x6000'501b}>(arg0, arg1, arg2);
}
constexpr void Rorw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x6000'503b}>(arg0, arg1, arg2);
}
constexpr void Sd([[maybe_unused]] Register arg0, [[maybe_unused]] const Label& arg1, [[maybe_unused]] Register arg2);
constexpr void Sd([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand<Register, SImmediate>& arg1) {
  EmitSTypeInstruction<uint32_t{0x0000'3023}>(arg0, arg1);
}
constexpr void SextW([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Slli([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift64Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'1013}>(arg0, arg1, arg2);
}
constexpr void Slliw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift32Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'101b}>(arg0, arg1, arg2);
}
constexpr void Sllw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x0000'103b}>(arg0, arg1, arg2);
}
constexpr void Srai([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift64Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x4000'5013}>(arg0, arg1, arg2);
}
constexpr void Sraiw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift32Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x4000'501b}>(arg0, arg1, arg2);
}
constexpr void Srli([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift64Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'5013}>(arg0, arg1, arg2);
}
constexpr void Srliw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Shift32Immediate arg2) {
  EmitITypeInstruction<uint32_t{0x0000'501b}>(arg0, arg1, arg2);
}
constexpr void Subw([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitRTypeInstruction<uint32_t{0x4000'003b}>(arg0, arg1, arg2);
}
constexpr void ZextW([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
