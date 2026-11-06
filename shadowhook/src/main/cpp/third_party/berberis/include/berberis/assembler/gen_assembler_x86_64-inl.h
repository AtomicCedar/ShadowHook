constexpr void Adcq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x13}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Adcq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x13}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Adcq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x11}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Adcq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x11}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Adcq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x11}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Adcq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AdcqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return AdcqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{2}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Adcq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Adcq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AdcqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{2}>(Memory64Bit(arg0), (arg1));
}

constexpr void Adcq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AdcqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{2}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Adcq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void AdcqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return AdcqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x15}>((arg0));
}
template<typename ImmType>
auto AdcqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void AdcqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{2}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto AdcqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void AdcqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{2}>(Memory64Bit(arg0), (arg1));
}

constexpr void AdcqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{2}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto AdcqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Addq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x01}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Addq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x01}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Addq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x01}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Addq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x03}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Addq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x03}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Addq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AddqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return AddqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{0}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Addq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Addq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AddqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{0}>(Memory64Bit(arg0), (arg1));
}

constexpr void Addq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AddqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{0}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Addq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void AddqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return AddqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x05}>((arg0));
}
template<typename ImmType>
auto AddqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void AddqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{0}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto AddqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void AddqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{0}>(Memory64Bit(arg0), (arg1));
}

constexpr void AddqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{0}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto AddqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Andnq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF2}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Andnq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Operand& arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF2}>(Register64Bit(arg0), Register64Bit(arg1), Memory64Bit(arg2));
}

constexpr void Andnq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const LabelOperand arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF2}>(Register64Bit(arg0), Register64Bit(arg1), Label64Bit(arg2));
}

constexpr void Andq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x21}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Andq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x21}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Andq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x21}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Andq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x23}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Andq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x23}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Andq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AndqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return AndqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{4}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Andq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Andq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AndqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{4}>(Memory64Bit(arg0), (arg1));
}

constexpr void Andq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return AndqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{4}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Andq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void AndqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return AndqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x25}>((arg0));
}
template<typename ImmType>
auto AndqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void AndqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{4}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto AndqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void AndqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{4}>(Memory64Bit(arg0), (arg1));
}

constexpr void AndqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{4}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto AndqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Bextrq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF7}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Bextrq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF7}>(Register64Bit(arg0), Memory64Bit(arg1), Register64Bit(arg2));
}

constexpr void Bextrq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF7}>(Register64Bit(arg0), Label64Bit(arg1), Register64Bit(arg2));
}

constexpr void Blsiq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{3}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Blsiq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{3}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Blsiq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{3}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Blsmskq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{2}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Blsmskq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{2}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Blsmskq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{2}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Blsrq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{1}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Blsrq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{1}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Blsrq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitRmToVexInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF3}, uint8_t{1}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Bsfq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBC}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Bsfq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBC}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Bsfq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBC}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Bsrq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBD}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Bsrq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBD}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Bsrq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBD}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Bswapq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xC8}>(Register64Bit(arg0));
}
constexpr void Btcq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xBB}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Btcq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xBB}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btcq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xBB}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btcq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{7}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Btcq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btcq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{7}>(Memory64Bit(arg0), (arg1));
}

constexpr void Btcq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{7}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Btcq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{4}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Btq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{4}>(Memory64Bit(arg0), (arg1));
}

constexpr void Btq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{4}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Btq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA3}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Btq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA3}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA3}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btrq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xB3}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Btrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xB3}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btrq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xB3}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btrq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{6}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Btrq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{6}>(Memory64Bit(arg0), (arg1));
}

constexpr void Btrq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{6}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Btrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btsq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAB}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Btsq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAB}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btsq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAB}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Btsq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{5}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Btsq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Btsq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{5}>(Memory64Bit(arg0), (arg1));
}

constexpr void Btsq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBA}, uint8_t{5}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Btsq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Bzhiq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Bzhiq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF5}>(Register64Bit(arg0), Memory64Bit(arg1), Register64Bit(arg2));
}

constexpr void Bzhiq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x80}, uint8_t{0xF5}>(Register64Bit(arg0), Label64Bit(arg1), Register64Bit(arg2));
}

constexpr void Callq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{2}>(VectorMemory64Bit(arg0));
}

constexpr void Callq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{2}>(VectorLabel64Bit(arg0));
}

constexpr void Cdqe() {
  EmitInstruction<uint8_t{0x48}, uint8_t{0x98}>();
}
constexpr void Cltq() {
  EmitInstruction<uint8_t{0x48}, uint8_t{0x98}>();
}
constexpr void Cmovq([[maybe_unused]] Condition arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0x40}>((arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Cmovq([[maybe_unused]] Condition arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Operand& arg2) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0x40}>((arg0), Register64Bit(arg1), Memory64Bit(arg2));
}

constexpr void Cmovq([[maybe_unused]] Condition arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const LabelOperand arg2) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0x40}>((arg0), Register64Bit(arg1), Label64Bit(arg2));
}

constexpr void CmpXchg16b([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xC7}, uint8_t{1}>(Memory128Bit(arg0));
}

constexpr void CmpXchg16b([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xC7}, uint8_t{1}>(Label128Bit(arg0));
}

constexpr void CmpXchgq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xB1}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void CmpXchgq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xB1}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void CmpXchgq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xB1}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Cmpq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x39}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Cmpq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x39}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Cmpq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x39}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Cmpq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return CmpqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return CmpqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{7}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Cmpq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Cmpq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return CmpqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{7}>(Memory64Bit(arg0), (arg1));
}

constexpr void Cmpq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return CmpqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{7}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Cmpq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Cmpq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x3B}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Cmpq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x3B}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void CmpqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return CmpqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x3D}>((arg0));
}
template<typename ImmType>
auto CmpqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void CmpqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{7}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto CmpqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void CmpqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{7}>(Memory64Bit(arg0), (arg1));
}

constexpr void CmpqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{7}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto CmpqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Cqo() {
  EmitInstruction<uint8_t{0x48}, uint8_t{0x99}>();
}
constexpr void Cqto() {
  EmitInstruction<uint8_t{0x48}, uint8_t{0x99}>();
}
constexpr void Crc32q([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x38}, uint8_t{0xF1}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Crc32q([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x38}, uint8_t{0xF1}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Crc32q([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x38}, uint8_t{0xF1}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Cvtsd2siq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2D}>(Register64Bit(arg0), VectorRegister128Bit(arg1));
}
constexpr void Cvtsd2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2D}>(Register64Bit(arg0), VectorMemory64Bit(arg1));
}

constexpr void Cvtsd2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2D}>(Register64Bit(arg0), VectorLabel64Bit(arg1));
}

constexpr void Cvtsi2sdq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2A}>(VectorRegister128Bit(arg0), Register64Bit(arg1));
}
constexpr void Cvtsi2sdq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2A}>(VectorRegister128Bit(arg0), Memory64Bit(arg1));
}

constexpr void Cvtsi2sdq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2A}>(VectorRegister128Bit(arg0), Label64Bit(arg1));
}

constexpr void Cvtsi2ssq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2A}>(VectorRegister128Bit(arg0), Register64Bit(arg1));
}
constexpr void Cvtsi2ssq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2A}>(VectorRegister128Bit(arg0), Memory64Bit(arg1));
}

constexpr void Cvtsi2ssq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2A}>(VectorRegister128Bit(arg0), Label64Bit(arg1));
}

constexpr void Cvtss2siq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2D}>(Register64Bit(arg0), VectorRegister128Bit(arg1));
}
constexpr void Cvtss2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2D}>(Register64Bit(arg0), Memory32Bit(arg1));
}

constexpr void Cvtss2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2D}>(Register64Bit(arg0), Label32Bit(arg1));
}

constexpr void Cvttsd2siq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2C}>(Register64Bit(arg0), VectorRegister128Bit(arg1));
}
constexpr void Cvttsd2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2C}>(Register64Bit(arg0), VectorMemory64Bit(arg1));
}

constexpr void Cvttsd2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF2}, uint8_t{0x0F}, uint8_t{0x2C}>(Register64Bit(arg0), VectorLabel64Bit(arg1));
}

constexpr void Cvttss2siq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2C}>(Register64Bit(arg0), VectorRegister128Bit(arg1));
}
constexpr void Cvttss2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2C}>(Register64Bit(arg0), Memory32Bit(arg1));
}

constexpr void Cvttss2siq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0x2C}>(Register64Bit(arg0), Label32Bit(arg1));
}

constexpr void Decl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{1}>(Register32Bit(arg0));
}
constexpr void Decq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{1}>(Register64Bit(arg0));
}
constexpr void Decq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{1}>(Memory64Bit(arg0));
}

constexpr void Decq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{1}>(Label64Bit(arg0));
}

constexpr void Decw([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0x66}, uint8_t{0xFF}, uint8_t{1}>(Register16Bit(arg0));
}
constexpr void Divq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{6}>(Register64Bit(arg0));
}
constexpr void Divq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{6}>(Memory64Bit(arg0));
}

constexpr void Divq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{6}>(Label64Bit(arg0));
}

constexpr void Fxrstor64([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAE}, uint8_t{1}>(Memory64Bit(arg0));
}

constexpr void Fxrstor64([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAE}, uint8_t{1}>(Label64Bit(arg0));
}

constexpr void Fxsave64([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAE}, uint8_t{0}>(Memory64Bit(arg0));
}

constexpr void Fxsave64([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAE}, uint8_t{0}>(Label64Bit(arg0));
}

constexpr void Idivq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{7}>(Register64Bit(arg0));
}
constexpr void Idivq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{7}>(Memory64Bit(arg0));
}

constexpr void Idivq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{7}>(Label64Bit(arg0));
}

constexpr void Imulq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{5}>(Register64Bit(arg0));
}
constexpr void Imulq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{5}>(Memory64Bit(arg0));
}

constexpr void Imulq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{5}>(Label64Bit(arg0));
}

constexpr void Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int32_t arg2) {
  if (IsInRange<int8_t>(arg2)) {
   return ImulqImm8(arg0, arg1, static_cast<int8_t>(arg2));
  }
  EmitInstruction<uint8_t{0x69}>(Register64Bit(arg0), Register64Bit(arg1), (arg2));
}
template<typename ImmType>
auto Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] int32_t arg2) {
  if (IsInRange<int8_t>(arg2)) {
   return ImulqImm8(arg0, arg1, static_cast<int8_t>(arg2));
  }
  EmitInstruction<uint8_t{0x69}>(Register64Bit(arg0), Memory64Bit(arg1), (arg2));
}

constexpr void Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] int32_t arg2) {
  if (IsInRange<int8_t>(arg2)) {
   return ImulqImm8(arg0, arg1, static_cast<int8_t>(arg2));
  }
  EmitInstruction<uint8_t{0x69}>(Register64Bit(arg0), Label64Bit(arg1), (arg2));
}

template<typename ImmType>
auto Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAF}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAF}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Imulq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xAF}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void ImulqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0x6B}>(Register64Bit(arg0), Register64Bit(arg1), (arg2));
}
template<typename ImmType>
auto ImulqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void ImulqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0x6B}>(Register64Bit(arg0), Memory64Bit(arg1), (arg2));
}

constexpr void ImulqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0x6B}>(Register64Bit(arg0), Label64Bit(arg1), (arg2));
}

template<typename ImmType>
auto ImulqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Incl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{0}>(Register32Bit(arg0));
}
constexpr void Incq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{0}>(Register64Bit(arg0));
}
constexpr void Incq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{0}>(Memory64Bit(arg0));
}

constexpr void Incq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{0}>(Label64Bit(arg0));
}

constexpr void Incw([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0x66}, uint8_t{0xFF}, uint8_t{0}>(Register16Bit(arg0));
}
constexpr void Jmpq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{4}>(VectorMemory64Bit(arg0));
}

constexpr void Jmpq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{4}>(VectorLabel64Bit(arg0));
}

constexpr void Leaq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x8D}>(Register64Bit(arg0), MemoryDefaultBit(arg1));
}

constexpr void Leaq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x8D}>(Register64Bit(arg0), LabelDefaultBit(arg1));
}

constexpr void LockCmpXchg16b([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF0}, uint8_t{0x0F}, uint8_t{0xC7}, uint8_t{1}>(Memory128Bit(arg0));
}

constexpr void LockCmpXchg16b([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF0}, uint8_t{0x0F}, uint8_t{0xC7}, uint8_t{1}>(Label128Bit(arg0));
}

constexpr void LockCmpXchgq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0xF0}, uint8_t{0x0F}, uint8_t{0xB1}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void LockCmpXchgq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0xF0}, uint8_t{0x0F}, uint8_t{0xB1}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void LockXaddq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0xF0}, uint8_t{0x0F}, uint8_t{0xC1}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void LockXaddq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0xF0}, uint8_t{0x0F}, uint8_t{0xC1}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Lzcntq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xBD}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Lzcntq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xBD}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Lzcntq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xBD}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Movq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1) {
  EmitRegToRmInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x7E}>(Register64Bit(arg0), VectorRegister128Bit(arg1));
}
constexpr void Movq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x6E}>(VectorRegister128Bit(arg0), Register64Bit(arg1));
}
constexpr void Movq([[maybe_unused]] Register arg0, [[maybe_unused]] int64_t arg1);
template<typename ImmType>
auto Movq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int64_t) < sizeof(ImmType)> = delete;
constexpr void Movq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x8B}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Movq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x8B}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Movq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x89}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Movq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x89}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Movq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x89}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Movq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  EmitInstruction<uint8_t{0xC7}, uint8_t{0}>(Memory64Bit(arg0), (arg1));
}

constexpr void Movq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  EmitInstruction<uint8_t{0xC7}, uint8_t{0}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Movq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Movsxbq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBE}>(Register64Bit(arg0), Register8Bit(arg1));
}
constexpr void Movsxbq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBE}>(Register64Bit(arg0), Memory8Bit(arg1));
}

constexpr void Movsxbq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBE}>(Register64Bit(arg0), Label8Bit(arg1));
}

constexpr void Movsxlq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x63}>(Register64Bit(arg0), Register32Bit(arg1));
}
constexpr void Movsxlq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x63}>(Register64Bit(arg0), Memory32Bit(arg1));
}

constexpr void Movsxlq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x63}>(Register64Bit(arg0), Label32Bit(arg1));
}

constexpr void Movsxwq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBF}>(Register64Bit(arg0), Register16Bit(arg1));
}
constexpr void Movsxwq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBF}>(Register64Bit(arg0), Memory16Bit(arg1));
}

constexpr void Movsxwq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xBF}>(Register64Bit(arg0), Label16Bit(arg1));
}

constexpr void Movzxbq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xB6}>(Register64Bit(arg0), Register8Bit(arg1));
}
constexpr void Movzxbq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xB6}>(Register64Bit(arg0), Memory8Bit(arg1));
}

constexpr void Movzxbq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xB6}>(Register64Bit(arg0), Label8Bit(arg1));
}

constexpr void Movzxwq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xB7}>(Register64Bit(arg0), Register16Bit(arg1));
}
constexpr void Movzxwq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xB7}>(Register64Bit(arg0), Memory16Bit(arg1));
}

constexpr void Movzxwq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0F}, uint8_t{0xB7}>(Register64Bit(arg0), Label16Bit(arg1));
}

constexpr void Mulq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{4}>(Register64Bit(arg0));
}
constexpr void Mulq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{4}>(Memory64Bit(arg0));
}

constexpr void Mulq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{4}>(Label64Bit(arg0));
}

constexpr void Mulxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x83}, uint8_t{0xF6}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Mulxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Operand& arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x83}, uint8_t{0xF6}>(Register64Bit(arg0), Register64Bit(arg1), Memory64Bit(arg2));
}

constexpr void Mulxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const LabelOperand arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x83}, uint8_t{0xF6}>(Register64Bit(arg0), Register64Bit(arg1), Label64Bit(arg2));
}

constexpr void Negq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{3}>(Register64Bit(arg0));
}
constexpr void Negq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{3}>(Memory64Bit(arg0));
}

constexpr void Negq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{3}>(Label64Bit(arg0));
}

constexpr void Notq([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{2}>(Register64Bit(arg0));
}
constexpr void Notq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{2}>(Memory64Bit(arg0));
}

constexpr void Notq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{2}>(Label64Bit(arg0));
}

constexpr void Orq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x09}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Orq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x09}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Orq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x09}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Orq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x0B}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Orq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x0B}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Orq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return OrqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return OrqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{1}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Orq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Orq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return OrqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{1}>(Memory64Bit(arg0), (arg1));
}

constexpr void Orq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return OrqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{1}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Orq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void OrqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return OrqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x0D}>((arg0));
}
template<typename ImmType>
auto OrqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void OrqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{1}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto OrqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void OrqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{1}>(Memory64Bit(arg0), (arg1));
}

constexpr void OrqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{1}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto OrqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Pdepq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x83}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Pdepq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Operand& arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x83}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Memory64Bit(arg2));
}

constexpr void Pdepq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const LabelOperand arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x83}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Label64Bit(arg2));
}

constexpr void Pextq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x82}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Pextq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const Operand& arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x82}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Memory64Bit(arg2));
}

constexpr void Pextq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] const LabelOperand arg2) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x82}, uint8_t{0x82}, uint8_t{0xF5}>(Register64Bit(arg0), Register64Bit(arg1), Label64Bit(arg2));
}

constexpr void Pextrq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x3A}, uint8_t{0x16}>(Register64Bit(arg0), VectorRegister128Bit(arg1), (arg2));
}
template<typename ImmType>
auto Pextrq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Pextrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x3A}, uint8_t{0x16}>(Memory64Bit(arg0), VectorRegister128Bit(arg1), (arg2));
}

constexpr void Pextrq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x3A}, uint8_t{0x16}>(Label64Bit(arg0), VectorRegister128Bit(arg1), (arg2));
}

template<typename ImmType>
auto Pextrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Pinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x3A}, uint8_t{0x22}>(VectorRegister128Bit(arg0), Register64Bit(arg1), (arg2));
}
template<typename ImmType>
auto Pinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Pinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x3A}, uint8_t{0x22}>(VectorRegister128Bit(arg0), Memory64Bit(arg1), (arg2));
}

constexpr void Pinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0x66}, uint8_t{0x0F}, uint8_t{0x3A}, uint8_t{0x22}>(VectorRegister128Bit(arg0), Label64Bit(arg1), (arg2));
}

template<typename ImmType>
auto Pinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Popcntq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xB8}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Popcntq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xB8}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Popcntq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xB8}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Popq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0x8F}, uint8_t{0}>(VectorMemory64Bit(arg0));
}

constexpr void Popq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0x8F}, uint8_t{0}>(VectorLabel64Bit(arg0));
}

constexpr void Pushq([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{6}>(VectorMemory64Bit(arg0));
}

constexpr void Pushq([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xFF}, uint8_t{6}>(VectorLabel64Bit(arg0));
}

constexpr void Rclq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RclqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{2}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Rclq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Rclq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RclqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{2}>(Memory64Bit(arg0), (arg1));
}

constexpr void Rclq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RclqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{2}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Rclq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void RclqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{2}>(Register64Bit(arg0));
}
constexpr void RclqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{2}>(Memory64Bit(arg0));
}

constexpr void RclqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{2}>(Label64Bit(arg0));
}

constexpr void RclqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{2}>(Register64Bit(arg0));
}
constexpr void RclqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{2}>(Memory64Bit(arg0));
}

constexpr void RclqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{2}>(Label64Bit(arg0));
}

constexpr void Rcrq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RcrqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{3}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Rcrq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Rcrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RcrqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{3}>(Memory64Bit(arg0), (arg1));
}

constexpr void Rcrq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RcrqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{3}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Rcrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void RcrqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{3}>(Register64Bit(arg0));
}
constexpr void RcrqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{3}>(Memory64Bit(arg0));
}

constexpr void RcrqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{3}>(Label64Bit(arg0));
}

constexpr void RcrqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{3}>(Register64Bit(arg0));
}
constexpr void RcrqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{3}>(Memory64Bit(arg0));
}

constexpr void RcrqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{3}>(Label64Bit(arg0));
}

constexpr void Rolq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RolqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{0}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Rolq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Rolq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RolqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{0}>(Memory64Bit(arg0), (arg1));
}

constexpr void Rolq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RolqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{0}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Rolq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void RolqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{0}>(Register64Bit(arg0));
}
constexpr void RolqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{0}>(Memory64Bit(arg0));
}

constexpr void RolqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{0}>(Label64Bit(arg0));
}

constexpr void RolqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{0}>(Register64Bit(arg0));
}
constexpr void RolqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{0}>(Memory64Bit(arg0));
}

constexpr void RolqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{0}>(Label64Bit(arg0));
}

constexpr void Rorq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RorqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{1}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Rorq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Rorq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RorqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{1}>(Memory64Bit(arg0), (arg1));
}

constexpr void Rorq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return RorqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{1}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Rorq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void RorqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{1}>(Register64Bit(arg0));
}
constexpr void RorqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{1}>(Memory64Bit(arg0));
}

constexpr void RorqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{1}>(Label64Bit(arg0));
}

constexpr void RorqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{1}>(Register64Bit(arg0));
}
constexpr void RorqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{1}>(Memory64Bit(arg0));
}

constexpr void RorqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{1}>(Label64Bit(arg0));
}

constexpr void Rorxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x83}, uint8_t{0xF0}>(Register64Bit(arg0), Register64Bit(arg1), (arg2));
}
template<typename ImmType>
auto Rorxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Rorxq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x83}, uint8_t{0xF0}>(Register64Bit(arg0), Memory64Bit(arg1), (arg2));
}

constexpr void Rorxq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] int8_t arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x83}, uint8_t{0xF0}>(Register64Bit(arg0), Label64Bit(arg1), (arg2));
}

template<typename ImmType>
auto Rorxq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Sarq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return SarqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{7}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Sarq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Sarq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return SarqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{7}>(Memory64Bit(arg0), (arg1));
}

constexpr void Sarq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return SarqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{7}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Sarq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void SarqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{7}>(Register64Bit(arg0));
}
constexpr void SarqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{7}>(Memory64Bit(arg0));
}

constexpr void SarqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{7}>(Label64Bit(arg0));
}

constexpr void SarqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{7}>(Register64Bit(arg0));
}
constexpr void SarqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{7}>(Memory64Bit(arg0));
}

constexpr void SarqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{7}>(Label64Bit(arg0));
}

constexpr void Sarxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x82}, uint8_t{0xF7}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Sarxq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x82}, uint8_t{0xF7}>(Register64Bit(arg0), Memory64Bit(arg1), Register64Bit(arg2));
}

constexpr void Sarxq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x82}, uint8_t{0xF7}>(Register64Bit(arg0), Label64Bit(arg1), Register64Bit(arg2));
}

constexpr void Sbbq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x1B}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Sbbq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x1B}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Sbbq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x19}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Sbbq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x19}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Sbbq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x19}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Sbbq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return SbbqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return SbbqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{3}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Sbbq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Sbbq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return SbbqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{3}>(Memory64Bit(arg0), (arg1));
}

constexpr void Sbbq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return SbbqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{3}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Sbbq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void SbbqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return SbbqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x1D}>((arg0));
}
template<typename ImmType>
auto SbbqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void SbbqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{3}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto SbbqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void SbbqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{3}>(Memory64Bit(arg0), (arg1));
}

constexpr void SbbqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{3}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto SbbqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Shldq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA4}>(Register64Bit(arg0), Register64Bit(arg1), (arg2));
}
template<typename ImmType>
auto Shldq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Shldq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA4}>(Memory64Bit(arg0), Register64Bit(arg1), (arg2));
}

constexpr void Shldq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA4}>(Label64Bit(arg0), Register64Bit(arg1), (arg2));
}

template<typename ImmType>
auto Shldq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void ShldqByCl([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA5}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void ShldqByCl([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA5}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void ShldqByCl([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xA5}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Shlq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return ShlqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{4}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Shlq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Shlq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return ShlqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{4}>(Memory64Bit(arg0), (arg1));
}

constexpr void Shlq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return ShlqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{4}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Shlq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void ShlqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{4}>(Register64Bit(arg0));
}
constexpr void ShlqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{4}>(Memory64Bit(arg0));
}

constexpr void ShlqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{4}>(Label64Bit(arg0));
}

constexpr void ShlqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{4}>(Register64Bit(arg0));
}
constexpr void ShlqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{4}>(Memory64Bit(arg0));
}

constexpr void ShlqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{4}>(Label64Bit(arg0));
}

constexpr void Shlxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x81}, uint8_t{0xF7}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Shlxq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x81}, uint8_t{0xF7}>(Register64Bit(arg0), Memory64Bit(arg1), Register64Bit(arg2));
}

constexpr void Shlxq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x81}, uint8_t{0xF7}>(Register64Bit(arg0), Label64Bit(arg1), Register64Bit(arg2));
}

constexpr void Shrdq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAC}>(Register64Bit(arg0), Register64Bit(arg1), (arg2));
}
template<typename ImmType>
auto Shrdq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Shrdq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAC}>(Memory64Bit(arg0), Register64Bit(arg1), (arg2));
}

constexpr void Shrdq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAC}>(Label64Bit(arg0), Register64Bit(arg1), (arg2));
}

template<typename ImmType>
auto Shrdq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void ShrdqByCl([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAD}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void ShrdqByCl([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAD}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void ShrdqByCl([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xAD}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Shrq([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return ShrqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{5}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Shrq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Shrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return ShrqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{5}>(Memory64Bit(arg0), (arg1));
}

constexpr void Shrq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  if (arg1 == 1) return ShrqByOne(arg0);
  EmitInstruction<uint8_t{0xC1}, uint8_t{5}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Shrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void ShrqByCl([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{5}>(Register64Bit(arg0));
}
constexpr void ShrqByCl([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{5}>(Memory64Bit(arg0));
}

constexpr void ShrqByCl([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD3}, uint8_t{5}>(Label64Bit(arg0));
}

constexpr void ShrqByOne([[maybe_unused]] Register arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{5}>(Register64Bit(arg0));
}
constexpr void ShrqByOne([[maybe_unused]] const Operand& arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{5}>(Memory64Bit(arg0));
}

constexpr void ShrqByOne([[maybe_unused]] const LabelOperand arg0) {
  EmitInstruction<uint8_t{0xD1}, uint8_t{5}>(Label64Bit(arg0));
}

constexpr void Shrxq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x83}, uint8_t{0xF7}>(Register64Bit(arg0), Register64Bit(arg1), Register64Bit(arg2));
}
constexpr void Shrxq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x83}, uint8_t{0xF7}>(Register64Bit(arg0), Memory64Bit(arg1), Register64Bit(arg2));
}

constexpr void Shrxq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1, [[maybe_unused]] Register arg2) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x02}, uint8_t{0x83}, uint8_t{0xF7}>(Register64Bit(arg0), Label64Bit(arg1), Register64Bit(arg2));
}

constexpr void Subq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x29}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Subq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x29}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Subq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x29}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Subq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x2B}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Subq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x2B}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Subq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return SubqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return SubqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{5}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Subq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Subq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return SubqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{5}>(Memory64Bit(arg0), (arg1));
}

constexpr void Subq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return SubqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{5}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Subq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void SubqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return SubqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x2D}>((arg0));
}
template<typename ImmType>
auto SubqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void SubqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{5}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto SubqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void SubqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{5}>(Memory64Bit(arg0), (arg1));
}

constexpr void SubqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{5}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto SubqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Testq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x85}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Testq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x85}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Testq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x85}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Testq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return TestqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0xF7}, uint8_t{0}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Testq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Testq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{0}>(Memory64Bit(arg0), (arg1));
}

constexpr void Testq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  EmitInstruction<uint8_t{0xF7}, uint8_t{0}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Testq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void TestqAccumulator([[maybe_unused]] int32_t arg0) {
  EmitInstruction<uint8_t{0x48}, uint8_t{0xA9}>((arg0));
}
template<typename ImmType>
auto TestqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Tzcntq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xBC}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Tzcntq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xBC}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Tzcntq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0xF3}, uint8_t{0x0F}, uint8_t{0xBC}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Vmovapd([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1);
constexpr void Vmovapd([[maybe_unused]] YMMRegister arg0, [[maybe_unused]] YMMRegister arg1);
constexpr void Vmovaps([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1);
constexpr void Vmovaps([[maybe_unused]] YMMRegister arg0, [[maybe_unused]] YMMRegister arg1);
constexpr void Vmovdqa([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1);
constexpr void Vmovdqa([[maybe_unused]] YMMRegister arg0, [[maybe_unused]] YMMRegister arg1);
constexpr void Vmovdqu([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1);
constexpr void Vmovdqu([[maybe_unused]] YMMRegister arg0, [[maybe_unused]] YMMRegister arg1);
constexpr void Vmovq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1) {
  EmitRegToRmInstruction<uint8_t{0xC4}, uint8_t{0x01}, uint8_t{0x81}, uint8_t{0x7E}>(Register64Bit(arg0), VectorRegister128Bit(arg1));
}
constexpr void Vmovq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] Register arg1) {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x01}, uint8_t{0x81}, uint8_t{0x6E}>(VectorRegister128Bit(arg0), Register64Bit(arg1));
}
constexpr void Vmovsd([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] XMMRegister arg2);
constexpr void Vmovss([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] XMMRegister arg2);
constexpr void Vpextrq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x81}, uint8_t{0x16}>(Register64Bit(arg0), VectorRegister128Bit(arg1), (arg2));
}
template<typename ImmType>
auto Vpextrq([[maybe_unused]] Register arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Vpextrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x81}, uint8_t{0x16}>(Memory64Bit(arg0), VectorRegister128Bit(arg1), (arg2));
}

constexpr void Vpextrq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] int8_t arg2) {
  EmitRegToRmInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x81}, uint8_t{0x16}>(Label64Bit(arg0), VectorRegister128Bit(arg1), (arg2));
}

template<typename ImmType>
auto Vpextrq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] ImmType arg2) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Vpinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] Register arg2, [[maybe_unused]] int8_t arg3) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x81}, uint8_t{0x22}>(VectorRegister128Bit(arg0), VectorRegister128Bit(arg1), Register64Bit(arg2), (arg3));
}
template<typename ImmType>
auto Vpinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] Register arg2, [[maybe_unused]] ImmType arg3) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Vpinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] const Operand& arg2, [[maybe_unused]] int8_t arg3) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x81}, uint8_t{0x22}>(VectorRegister128Bit(arg0), VectorRegister128Bit(arg1), Memory64Bit(arg2), (arg3));
}

constexpr void Vpinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] const LabelOperand arg2, [[maybe_unused]] int8_t arg3) {
  EmitVexRmToRegInstruction<uint8_t{0xC4}, uint8_t{0x03}, uint8_t{0x81}, uint8_t{0x22}>(VectorRegister128Bit(arg0), VectorRegister128Bit(arg1), Label64Bit(arg2), (arg3));
}

template<typename ImmType>
auto Vpinsrq([[maybe_unused]] XMMRegister arg0, [[maybe_unused]] XMMRegister arg1, [[maybe_unused]] const Operand& arg2, [[maybe_unused]] ImmType arg3) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void Vzeroall() {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x01}, uint8_t{0x04}, uint8_t{0x77}>();
}
constexpr void Vzeroupper() {
  EmitInstruction<uint8_t{0xC4}, uint8_t{0x01}, uint8_t{0x00}, uint8_t{0x77}>();
}
constexpr void Xaddq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xC1}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Xaddq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x0F}, uint8_t{0xC1}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Xchgq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1);
constexpr void Xchgq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x87}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Xchgq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x87}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Xlatb() {
  EmitInstruction<uint8_t{0xd7}>();
}
constexpr void Xorq([[maybe_unused]] Register arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x31}>(Register64Bit(arg0), Register64Bit(arg1));
}
constexpr void Xorq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x31}>(Memory64Bit(arg0), Register64Bit(arg1));
}

constexpr void Xorq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] Register arg1) {
  EmitRegToRmInstruction<uint8_t{0x31}>(Label64Bit(arg0), Register64Bit(arg1));
}

constexpr void Xorq([[maybe_unused]] Register arg0, [[maybe_unused]] const Operand& arg1) {
  EmitInstruction<uint8_t{0x33}>(Register64Bit(arg0), Memory64Bit(arg1));
}

constexpr void Xorq([[maybe_unused]] Register arg0, [[maybe_unused]] const LabelOperand arg1) {
  EmitInstruction<uint8_t{0x33}>(Register64Bit(arg0), Label64Bit(arg1));
}

constexpr void Xorq([[maybe_unused]] Register arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return XorqImm8(arg0, static_cast<int8_t>(arg1));
  }
  if (DerivedAssemblerType::IsAccumulator(arg0)) {
  return XorqAccumulator(arg1);
}
  EmitInstruction<uint8_t{0x81}, uint8_t{6}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto Xorq([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void Xorq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return XorqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{6}>(Memory64Bit(arg0), (arg1));
}

constexpr void Xorq([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int32_t arg1) {
  if (IsInRange<int8_t>(arg1)) {
   return XorqImm8(arg0, static_cast<int8_t>(arg1));
  }
  EmitInstruction<uint8_t{0x81}, uint8_t{6}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto Xorq([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void XorqAccumulator([[maybe_unused]] int32_t arg0) {
  if (IsInRange<int8_t>(arg0)) {
    return XorqImm8(DerivedAssemblerType::Accumulator(), static_cast<int8_t>(arg0));
  }
  EmitInstruction<uint8_t{0x48}, uint8_t{0x35}>((arg0));
}
template<typename ImmType>
auto XorqAccumulator([[maybe_unused]] ImmType arg0) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int32_t) < sizeof(ImmType)> = delete;
constexpr void XorqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{6}>(Register64Bit(arg0), (arg1));
}
template<typename ImmType>
auto XorqImm8([[maybe_unused]] Register arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void XorqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{6}>(Memory64Bit(arg0), (arg1));
}

constexpr void XorqImm8([[maybe_unused]] const LabelOperand arg0, [[maybe_unused]] int8_t arg1) {
  EmitInstruction<uint8_t{0x83}, uint8_t{6}>(Label64Bit(arg0), (arg1));
}

template<typename ImmType>
auto XorqImm8([[maybe_unused]] const Operand& arg0, [[maybe_unused]] ImmType arg1) -> std::enable_if_t<std::is_integral_v<ImmType> && sizeof(int8_t) < sizeof(ImmType)> = delete;
constexpr void AdcqRegMemAbsolute(Register arg0, int32_t arg1) {
  Adcq(arg0, {.disp = arg1});
}
constexpr void AdcqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Adcq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void AdcqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Adcq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void AdcqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Adcq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void AdcqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Adcq({.disp = arg0}, arg1);
}
constexpr void AdcqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Adcq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AdcqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Adcq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AdcqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Adcq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AdcqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Adcq({.disp = arg0}, arg1);
}
constexpr void AdcqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Adcq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AdcqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Adcq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AdcqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Adcq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AdcqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  AdcqImm8({.disp = arg0}, arg1);
}
constexpr void AdcqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  AdcqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AdcqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  AdcqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AdcqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  AdcqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AddqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Addq({.disp = arg0}, arg1);
}
constexpr void AddqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Addq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AddqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Addq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AddqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Addq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AddqRegMemAbsolute(Register arg0, int32_t arg1) {
  Addq(arg0, {.disp = arg1});
}
constexpr void AddqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Addq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void AddqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Addq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void AddqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Addq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void AddqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Addq({.disp = arg0}, arg1);
}
constexpr void AddqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Addq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AddqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Addq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AddqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Addq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AddqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  AddqImm8({.disp = arg0}, arg1);
}
constexpr void AddqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  AddqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AddqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  AddqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AddqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  AddqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AndnqRegRegMemAbsolute(Register arg0, Register arg1, int32_t arg2) {
  Andnq(arg0, arg1, {.disp = arg2});
}
constexpr void AndnqRegRegMemBaseDisp(Register arg0, Register arg1, Register arg2_base, int32_t arg2_disp) {
  Andnq(arg0, arg1, {.base = arg2_base, .disp = arg2_disp});
}
constexpr void AndnqRegRegMemIndexDisp(Register arg0, Register arg1, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Andnq(arg0, arg1, {.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void AndnqRegRegMemBaseIndexDisp(Register arg0, Register arg1, Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Andnq(arg0, arg1, {.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void AndqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Andq({.disp = arg0}, arg1);
}
constexpr void AndqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Andq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AndqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Andq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AndqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Andq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AndqRegMemAbsolute(Register arg0, int32_t arg1) {
  Andq(arg0, {.disp = arg1});
}
constexpr void AndqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Andq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void AndqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Andq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void AndqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Andq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void AndqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Andq({.disp = arg0}, arg1);
}
constexpr void AndqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Andq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AndqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Andq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AndqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Andq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AndqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  AndqImm8({.disp = arg0}, arg1);
}
constexpr void AndqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  AndqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void AndqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  AndqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void AndqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  AndqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BextrqRegMemAbsoluteReg(Register arg0, int32_t arg1, Register arg2) {
  Bextrq(arg0, {.disp = arg1}, arg2);
}
constexpr void BextrqRegMemBaseDispReg(Register arg0, Register arg1_base, int32_t arg1_disp, Register arg2) {
  Bextrq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void BextrqRegMemIndexDispReg(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Bextrq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void BextrqRegMemBaseIndexDispReg(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Bextrq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void BlsiqRegMemAbsolute(Register arg0, int32_t arg1) {
  Blsiq(arg0, {.disp = arg1});
}
constexpr void BlsiqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Blsiq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void BlsiqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Blsiq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BlsiqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Blsiq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BlsmskqRegMemAbsolute(Register arg0, int32_t arg1) {
  Blsmskq(arg0, {.disp = arg1});
}
constexpr void BlsmskqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Blsmskq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void BlsmskqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Blsmskq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BlsmskqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Blsmskq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BlsrqRegMemAbsolute(Register arg0, int32_t arg1) {
  Blsrq(arg0, {.disp = arg1});
}
constexpr void BlsrqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Blsrq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void BlsrqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Blsrq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BlsrqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Blsrq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BsfqRegMemAbsolute(Register arg0, int32_t arg1) {
  Bsfq(arg0, {.disp = arg1});
}
constexpr void BsfqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Bsfq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void BsfqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Bsfq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BsfqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Bsfq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BsrqRegMemAbsolute(Register arg0, int32_t arg1) {
  Bsrq(arg0, {.disp = arg1});
}
constexpr void BsrqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Bsrq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void BsrqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Bsrq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BsrqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Bsrq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void BtcqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Btcq({.disp = arg0}, arg1);
}
constexpr void BtcqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Btcq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtcqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btcq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtcqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btcq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtcqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Btcq({.disp = arg0}, arg1);
}
constexpr void BtcqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Btcq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtcqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btcq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtcqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btcq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Btq({.disp = arg0}, arg1);
}
constexpr void BtqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Btq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Btq({.disp = arg0}, arg1);
}
constexpr void BtqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Btq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtrqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Btrq({.disp = arg0}, arg1);
}
constexpr void BtrqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Btrq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtrqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btrq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtrqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btrq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtrqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Btrq({.disp = arg0}, arg1);
}
constexpr void BtrqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Btrq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtrqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btrq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtrqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btrq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtsqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Btsq({.disp = arg0}, arg1);
}
constexpr void BtsqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Btsq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtsqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btsq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtsqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Btsq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtsqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Btsq({.disp = arg0}, arg1);
}
constexpr void BtsqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Btsq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void BtsqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btsq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BtsqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Btsq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void BzhiqRegMemAbsoluteReg(Register arg0, int32_t arg1, Register arg2) {
  Bzhiq(arg0, {.disp = arg1}, arg2);
}
constexpr void BzhiqRegMemBaseDispReg(Register arg0, Register arg1_base, int32_t arg1_disp, Register arg2) {
  Bzhiq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void BzhiqRegMemIndexDispReg(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Bzhiq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void BzhiqRegMemBaseIndexDispReg(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Bzhiq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void CallqRegMemAbsolute(int32_t arg1) {
  Callq({.disp = arg1});
}
constexpr void CallqRegMemBaseDisp(Register arg1_base, int32_t arg1_disp) {
  Callq({.base = arg1_base, .disp = arg1_disp});
}
constexpr void CallqRegMemIndexDisp(Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Callq({.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void CallqRegMemBaseIndexDisp(Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Callq({.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void CmovqRegMemAbsolute(Condition arg0, Register arg1, int32_t arg2) {
  Cmovq(arg0, arg1, {.disp = arg2});
}
constexpr void CmovqRegMemBaseDisp(Condition arg0, Register arg1, Register arg2_base, int32_t arg2_disp) {
  Cmovq(arg0, arg1, {.base = arg2_base, .disp = arg2_disp});
}
constexpr void CmovqRegMemIndexDisp(Condition arg0, Register arg1, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Cmovq(arg0, arg1, {.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void CmovqRegMemBaseIndexDisp(Condition arg0, Register arg1, Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Cmovq(arg0, arg1, {.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void CmpXchg16bRegRegRegRegMemAbsolute(int32_t arg4) {
  CmpXchg16b({.disp = arg4});
}
constexpr void CmpXchg16bRegRegRegRegMemBaseDisp(Register arg4_base, int32_t arg4_disp) {
  CmpXchg16b({.base = arg4_base, .disp = arg4_disp});
}
constexpr void CmpXchg16bRegRegRegRegMemIndexDisp(Register arg4_index, ScaleFactor arg4_scale, int32_t arg4_disp) {
  CmpXchg16b({.index = arg4_index, .scale = arg4_scale, .disp = arg4_disp});
}
constexpr void CmpXchg16bRegRegRegRegMemBaseIndexDisp(Register arg4_base, Register arg4_index, ScaleFactor arg4_scale, int32_t arg4_disp) {
  CmpXchg16b({.base = arg4_base, .index = arg4_index, .scale = arg4_scale, .disp = arg4_disp});
}
constexpr void CmpXchgqRegMemAbsoluteReg(int32_t arg1, Register arg2) {
  CmpXchgq({.disp = arg1}, arg2);
}
constexpr void CmpXchgqRegMemBaseDispReg(Register arg1_base, int32_t arg1_disp, Register arg2) {
  CmpXchgq({.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void CmpXchgqRegMemIndexDispReg(Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  CmpXchgq({.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void CmpXchgqRegMemBaseIndexDispReg(Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  CmpXchgq({.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void CmpqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Cmpq({.disp = arg0}, arg1);
}
constexpr void CmpqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Cmpq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void CmpqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Cmpq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void CmpqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Cmpq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void CmpqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Cmpq({.disp = arg0}, arg1);
}
constexpr void CmpqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Cmpq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void CmpqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Cmpq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void CmpqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Cmpq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void CmpqRegMemAbsolute(Register arg0, int32_t arg1) {
  Cmpq(arg0, {.disp = arg1});
}
constexpr void CmpqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Cmpq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void CmpqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cmpq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void CmpqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cmpq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void CmpqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  CmpqImm8({.disp = arg0}, arg1);
}
constexpr void CmpqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  CmpqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void CmpqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  CmpqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void CmpqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  CmpqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void Crc32qRegMemAbsolute(Register arg0, int32_t arg1) {
  Crc32q(arg0, {.disp = arg1});
}
constexpr void Crc32qRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Crc32q(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Crc32qRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Crc32q(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Crc32qRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Crc32q(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtsd2siqRegMemAbsolute(Register arg0, int32_t arg1) {
  Cvtsd2siq(arg0, {.disp = arg1});
}
constexpr void Cvtsd2siqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Cvtsd2siq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Cvtsd2siqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtsd2siq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtsd2siqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtsd2siq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtsi2sdqXRegMemAbsolute(XMMRegister arg0, int32_t arg1) {
  Cvtsi2sdq(arg0, {.disp = arg1});
}
constexpr void Cvtsi2sdqXRegMemBaseDisp(XMMRegister arg0, Register arg1_base, int32_t arg1_disp) {
  Cvtsi2sdq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Cvtsi2sdqXRegMemIndexDisp(XMMRegister arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtsi2sdq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtsi2sdqXRegMemBaseIndexDisp(XMMRegister arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtsi2sdq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtsi2ssqXRegMemAbsolute(XMMRegister arg0, int32_t arg1) {
  Cvtsi2ssq(arg0, {.disp = arg1});
}
constexpr void Cvtsi2ssqXRegMemBaseDisp(XMMRegister arg0, Register arg1_base, int32_t arg1_disp) {
  Cvtsi2ssq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Cvtsi2ssqXRegMemIndexDisp(XMMRegister arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtsi2ssq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtsi2ssqXRegMemBaseIndexDisp(XMMRegister arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtsi2ssq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtss2siqRegMemAbsolute(Register arg0, int32_t arg1) {
  Cvtss2siq(arg0, {.disp = arg1});
}
constexpr void Cvtss2siqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Cvtss2siq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Cvtss2siqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtss2siq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvtss2siqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvtss2siq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvttsd2siqRegMemAbsolute(Register arg0, int32_t arg1) {
  Cvttsd2siq(arg0, {.disp = arg1});
}
constexpr void Cvttsd2siqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Cvttsd2siq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Cvttsd2siqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvttsd2siq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvttsd2siqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvttsd2siq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvttss2siqRegMemAbsolute(Register arg0, int32_t arg1) {
  Cvttss2siq(arg0, {.disp = arg1});
}
constexpr void Cvttss2siqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Cvttss2siq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void Cvttss2siqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvttss2siq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Cvttss2siqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Cvttss2siq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void DecqMemAbsolute(int32_t arg0) {
  Decq({.disp = arg0});
}
constexpr void DecqMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  Decq({.base = arg0_base, .disp = arg0_disp});
}
constexpr void DecqMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Decq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void DecqMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Decq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void DivqRegRegMemAbsolute(int32_t arg2) {
  Divq({.disp = arg2});
}
constexpr void DivqRegRegMemBaseDisp(Register arg2_base, int32_t arg2_disp) {
  Divq({.base = arg2_base, .disp = arg2_disp});
}
constexpr void DivqRegRegMemIndexDisp(Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Divq({.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void DivqRegRegMemBaseIndexDisp(Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Divq({.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void Fxrstor64MemAbsoluteReg(int32_t arg0) {
  Fxrstor64({.disp = arg0});
}
constexpr void Fxrstor64MemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  Fxrstor64({.base = arg0_base, .disp = arg0_disp});
}
constexpr void Fxrstor64MemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Fxrstor64({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void Fxrstor64MemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Fxrstor64({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void Fxsave64RegMemAbsolute(int32_t arg1) {
  Fxsave64({.disp = arg1});
}
constexpr void Fxsave64RegMemBaseDisp(Register arg1_base, int32_t arg1_disp) {
  Fxsave64({.base = arg1_base, .disp = arg1_disp});
}
constexpr void Fxsave64RegMemIndexDisp(Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Fxsave64({.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void Fxsave64RegMemBaseIndexDisp(Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Fxsave64({.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void IdivqRegRegMemAbsolute(int32_t arg2) {
  Idivq({.disp = arg2});
}
constexpr void IdivqRegRegMemBaseDisp(Register arg2_base, int32_t arg2_disp) {
  Idivq({.base = arg2_base, .disp = arg2_disp});
}
constexpr void IdivqRegRegMemIndexDisp(Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Idivq({.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void IdivqRegRegMemBaseIndexDisp(Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Idivq({.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void ImulqRegRegMemAbsolute(int32_t arg2) {
  Imulq({.disp = arg2});
}
constexpr void ImulqRegRegMemBaseDisp(Register arg2_base, int32_t arg2_disp) {
  Imulq({.base = arg2_base, .disp = arg2_disp});
}
constexpr void ImulqRegRegMemIndexDisp(Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Imulq({.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void ImulqRegRegMemBaseIndexDisp(Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Imulq({.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void ImulqRegMemAbsoluteImm(Register arg0, int32_t arg1, int32_t arg2) {
  Imulq(arg0, {.disp = arg1}, arg2);
}
constexpr void ImulqRegMemBaseDispImm(Register arg0, Register arg1_base, int32_t arg1_disp, int32_t arg2) {
  Imulq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void ImulqRegMemIndexDispImm(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int32_t arg2) {
  Imulq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void ImulqRegMemBaseIndexDispImm(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int32_t arg2) {
  Imulq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void ImulqRegMemAbsolute(Register arg0, int32_t arg1) {
  Imulq(arg0, {.disp = arg1});
}
constexpr void ImulqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Imulq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void ImulqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Imulq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void ImulqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Imulq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void ImulqImm8RegMemAbsoluteImm(Register arg0, int32_t arg1, int8_t arg2) {
  ImulqImm8(arg0, {.disp = arg1}, arg2);
}
constexpr void ImulqImm8RegMemBaseDispImm(Register arg0, Register arg1_base, int32_t arg1_disp, int8_t arg2) {
  ImulqImm8(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void ImulqImm8RegMemIndexDispImm(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int8_t arg2) {
  ImulqImm8(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void ImulqImm8RegMemBaseIndexDispImm(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int8_t arg2) {
  ImulqImm8(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void IncqMemAbsolute(int32_t arg0) {
  Incq({.disp = arg0});
}
constexpr void IncqMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  Incq({.base = arg0_base, .disp = arg0_disp});
}
constexpr void IncqMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Incq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void IncqMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Incq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void JmpqMemAbsolute(int32_t arg0) {
  Jmpq({.disp = arg0});
}
constexpr void JmpqMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  Jmpq({.base = arg0_base, .disp = arg0_disp});
}
constexpr void JmpqMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Jmpq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void JmpqMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Jmpq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void LeaqRegMemAbsolute(Register arg0, int32_t arg1) {
  Leaq(arg0, {.disp = arg1});
}
constexpr void LeaqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Leaq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void LeaqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Leaq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void LeaqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Leaq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void LockCmpXchg16bRegRegRegRegMemAbsolute(int32_t arg4) {
  LockCmpXchg16b({.disp = arg4});
}
constexpr void LockCmpXchg16bRegRegRegRegMemBaseDisp(Register arg4_base, int32_t arg4_disp) {
  LockCmpXchg16b({.base = arg4_base, .disp = arg4_disp});
}
constexpr void LockCmpXchg16bRegRegRegRegMemIndexDisp(Register arg4_index, ScaleFactor arg4_scale, int32_t arg4_disp) {
  LockCmpXchg16b({.index = arg4_index, .scale = arg4_scale, .disp = arg4_disp});
}
constexpr void LockCmpXchg16bRegRegRegRegMemBaseIndexDisp(Register arg4_base, Register arg4_index, ScaleFactor arg4_scale, int32_t arg4_disp) {
  LockCmpXchg16b({.base = arg4_base, .index = arg4_index, .scale = arg4_scale, .disp = arg4_disp});
}
constexpr void LockCmpXchgqRegMemAbsoluteReg(int32_t arg1, Register arg2) {
  LockCmpXchgq({.disp = arg1}, arg2);
}
constexpr void LockCmpXchgqRegMemBaseDispReg(Register arg1_base, int32_t arg1_disp, Register arg2) {
  LockCmpXchgq({.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void LockCmpXchgqRegMemIndexDispReg(Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  LockCmpXchgq({.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void LockCmpXchgqRegMemBaseIndexDispReg(Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  LockCmpXchgq({.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void LockXaddqMemAbsoluteReg(int32_t arg0, Register arg1) {
  LockXaddq({.disp = arg0}, arg1);
}
constexpr void LockXaddqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  LockXaddq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void LockXaddqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  LockXaddq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void LockXaddqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  LockXaddq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void LzcntqRegMemAbsolute(Register arg0, int32_t arg1) {
  Lzcntq(arg0, {.disp = arg1});
}
constexpr void LzcntqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Lzcntq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void LzcntqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Lzcntq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void LzcntqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Lzcntq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovqRegMemAbsolute(Register arg0, int32_t arg1) {
  Movq(arg0, {.disp = arg1});
}
constexpr void MovqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Movq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void MovqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Movq({.disp = arg0}, arg1);
}
constexpr void MovqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Movq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void MovqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Movq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void MovqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Movq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void MovqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Movq({.disp = arg0}, arg1);
}
constexpr void MovqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Movq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void MovqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Movq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void MovqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Movq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void MovsxbqRegMemAbsolute(Register arg0, int32_t arg1) {
  Movsxbq(arg0, {.disp = arg1});
}
constexpr void MovsxbqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Movsxbq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void MovsxbqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movsxbq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovsxbqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movsxbq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovsxlqRegMemAbsolute(Register arg0, int32_t arg1) {
  Movsxlq(arg0, {.disp = arg1});
}
constexpr void MovsxlqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Movsxlq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void MovsxlqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movsxlq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovsxlqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movsxlq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovsxwqRegMemAbsolute(Register arg0, int32_t arg1) {
  Movsxwq(arg0, {.disp = arg1});
}
constexpr void MovsxwqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Movsxwq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void MovsxwqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movsxwq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovsxwqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movsxwq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovzxbqRegMemAbsolute(Register arg0, int32_t arg1) {
  Movzxbq(arg0, {.disp = arg1});
}
constexpr void MovzxbqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Movzxbq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void MovzxbqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movzxbq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovzxbqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movzxbq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovzxwqRegMemAbsolute(Register arg0, int32_t arg1) {
  Movzxwq(arg0, {.disp = arg1});
}
constexpr void MovzxwqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Movzxwq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void MovzxwqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movzxwq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MovzxwqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Movzxwq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void MulqRegRegMemAbsolute(int32_t arg2) {
  Mulq({.disp = arg2});
}
constexpr void MulqRegRegMemBaseDisp(Register arg2_base, int32_t arg2_disp) {
  Mulq({.base = arg2_base, .disp = arg2_disp});
}
constexpr void MulqRegRegMemIndexDisp(Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Mulq({.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void MulqRegRegMemBaseIndexDisp(Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Mulq({.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void MulxqRegRegMemAbsolute(Register arg0, Register arg1, int32_t arg2) {
  Mulxq(arg0, arg1, {.disp = arg2});
}
constexpr void MulxqRegRegMemBaseDisp(Register arg0, Register arg1, Register arg2_base, int32_t arg2_disp) {
  Mulxq(arg0, arg1, {.base = arg2_base, .disp = arg2_disp});
}
constexpr void MulxqRegRegMemIndexDisp(Register arg0, Register arg1, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Mulxq(arg0, arg1, {.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void MulxqRegRegMemBaseIndexDisp(Register arg0, Register arg1, Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Mulxq(arg0, arg1, {.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void NegqMemAbsolute(int32_t arg0) {
  Negq({.disp = arg0});
}
constexpr void NegqMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  Negq({.base = arg0_base, .disp = arg0_disp});
}
constexpr void NegqMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Negq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void NegqMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Negq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void NotqMemAbsolute(int32_t arg0) {
  Notq({.disp = arg0});
}
constexpr void NotqMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  Notq({.base = arg0_base, .disp = arg0_disp});
}
constexpr void NotqMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Notq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void NotqMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  Notq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void OrqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Orq({.disp = arg0}, arg1);
}
constexpr void OrqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Orq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void OrqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Orq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void OrqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Orq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void OrqRegMemAbsolute(Register arg0, int32_t arg1) {
  Orq(arg0, {.disp = arg1});
}
constexpr void OrqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Orq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void OrqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Orq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void OrqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Orq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void OrqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Orq({.disp = arg0}, arg1);
}
constexpr void OrqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Orq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void OrqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Orq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void OrqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Orq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void OrqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  OrqImm8({.disp = arg0}, arg1);
}
constexpr void OrqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  OrqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void OrqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  OrqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void OrqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  OrqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void PdepqRegRegMemAbsolute(Register arg0, Register arg1, int32_t arg2) {
  Pdepq(arg0, arg1, {.disp = arg2});
}
constexpr void PdepqRegRegMemBaseDisp(Register arg0, Register arg1, Register arg2_base, int32_t arg2_disp) {
  Pdepq(arg0, arg1, {.base = arg2_base, .disp = arg2_disp});
}
constexpr void PdepqRegRegMemIndexDisp(Register arg0, Register arg1, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Pdepq(arg0, arg1, {.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void PdepqRegRegMemBaseIndexDisp(Register arg0, Register arg1, Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Pdepq(arg0, arg1, {.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void PextqRegRegMemAbsolute(Register arg0, Register arg1, int32_t arg2) {
  Pextq(arg0, arg1, {.disp = arg2});
}
constexpr void PextqRegRegMemBaseDisp(Register arg0, Register arg1, Register arg2_base, int32_t arg2_disp) {
  Pextq(arg0, arg1, {.base = arg2_base, .disp = arg2_disp});
}
constexpr void PextqRegRegMemIndexDisp(Register arg0, Register arg1, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Pextq(arg0, arg1, {.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void PextqRegRegMemBaseIndexDisp(Register arg0, Register arg1, Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp) {
  Pextq(arg0, arg1, {.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp});
}
constexpr void PextrqMemAbsoluteXRegImm(int32_t arg0, XMMRegister arg1, int8_t arg2) {
  Pextrq({.disp = arg0}, arg1, arg2);
}
constexpr void PextrqMemBaseDispXRegImm(Register arg0_base, int32_t arg0_disp, XMMRegister arg1, int8_t arg2) {
  Pextrq({.base = arg0_base, .disp = arg0_disp}, arg1, arg2);
}
constexpr void PextrqMemIndexDispXRegImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, XMMRegister arg1, int8_t arg2) {
  Pextrq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void PextrqMemBaseIndexDispXRegImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, XMMRegister arg1, int8_t arg2) {
  Pextrq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void PinsrqXRegMemAbsoluteImm(XMMRegister arg0, int32_t arg1, int8_t arg2) {
  Pinsrq(arg0, {.disp = arg1}, arg2);
}
constexpr void PinsrqXRegMemBaseDispImm(XMMRegister arg0, Register arg1_base, int32_t arg1_disp, int8_t arg2) {
  Pinsrq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void PinsrqXRegMemIndexDispImm(XMMRegister arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int8_t arg2) {
  Pinsrq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void PinsrqXRegMemBaseIndexDispImm(XMMRegister arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int8_t arg2) {
  Pinsrq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void PopcntqRegMemAbsolute(Register arg0, int32_t arg1) {
  Popcntq(arg0, {.disp = arg1});
}
constexpr void PopcntqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Popcntq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void PopcntqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Popcntq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void PopcntqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Popcntq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void PopqRegMemAbsolute(int32_t arg1) {
  Popq({.disp = arg1});
}
constexpr void PopqRegMemBaseDisp(Register arg1_base, int32_t arg1_disp) {
  Popq({.base = arg1_base, .disp = arg1_disp});
}
constexpr void PopqRegMemIndexDisp(Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Popq({.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void PopqRegMemBaseIndexDisp(Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Popq({.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void PushqRegMemAbsolute(int32_t arg1) {
  Pushq({.disp = arg1});
}
constexpr void PushqRegMemBaseDisp(Register arg1_base, int32_t arg1_disp) {
  Pushq({.base = arg1_base, .disp = arg1_disp});
}
constexpr void PushqRegMemIndexDisp(Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Pushq({.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void PushqRegMemBaseIndexDisp(Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Pushq({.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void RclqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Rclq({.disp = arg0}, arg1);
}
constexpr void RclqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Rclq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void RclqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rclq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RclqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rclq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RclqMemAbsoluteReg(int32_t arg0) {
  RclqByCl({.disp = arg0});
}
constexpr void RclqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  RclqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RclqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RclqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RclqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RclqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RclqByOneMemAbsolute(int32_t arg0) {
  RclqByOne({.disp = arg0});
}
constexpr void RclqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  RclqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RclqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RclqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RclqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RclqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RcrqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Rcrq({.disp = arg0}, arg1);
}
constexpr void RcrqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Rcrq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void RcrqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rcrq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RcrqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rcrq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RcrqMemAbsoluteReg(int32_t arg0) {
  RcrqByCl({.disp = arg0});
}
constexpr void RcrqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  RcrqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RcrqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RcrqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RcrqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RcrqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RcrqByOneMemAbsolute(int32_t arg0) {
  RcrqByOne({.disp = arg0});
}
constexpr void RcrqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  RcrqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RcrqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RcrqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RcrqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RcrqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RolqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Rolq({.disp = arg0}, arg1);
}
constexpr void RolqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Rolq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void RolqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rolq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RolqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rolq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RolqMemAbsoluteReg(int32_t arg0) {
  RolqByCl({.disp = arg0});
}
constexpr void RolqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  RolqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RolqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RolqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RolqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RolqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RolqByOneMemAbsolute(int32_t arg0) {
  RolqByOne({.disp = arg0});
}
constexpr void RolqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  RolqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RolqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RolqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RolqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RolqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RorqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Rorq({.disp = arg0}, arg1);
}
constexpr void RorqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Rorq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void RorqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rorq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RorqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Rorq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void RorqMemAbsoluteReg(int32_t arg0) {
  RorqByCl({.disp = arg0});
}
constexpr void RorqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  RorqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RorqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RorqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RorqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RorqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RorqByOneMemAbsolute(int32_t arg0) {
  RorqByOne({.disp = arg0});
}
constexpr void RorqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  RorqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void RorqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RorqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RorqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  RorqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void RorxqRegMemAbsoluteImm(Register arg0, int32_t arg1, int8_t arg2) {
  Rorxq(arg0, {.disp = arg1}, arg2);
}
constexpr void RorxqRegMemBaseDispImm(Register arg0, Register arg1_base, int32_t arg1_disp, int8_t arg2) {
  Rorxq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void RorxqRegMemIndexDispImm(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int8_t arg2) {
  Rorxq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void RorxqRegMemBaseIndexDispImm(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, int8_t arg2) {
  Rorxq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void SarqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Sarq({.disp = arg0}, arg1);
}
constexpr void SarqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Sarq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SarqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Sarq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SarqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Sarq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SarqMemAbsoluteReg(int32_t arg0) {
  SarqByCl({.disp = arg0});
}
constexpr void SarqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  SarqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void SarqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  SarqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void SarqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  SarqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void SarqByOneMemAbsolute(int32_t arg0) {
  SarqByOne({.disp = arg0});
}
constexpr void SarqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  SarqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void SarqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  SarqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void SarqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  SarqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void SarxqRegMemAbsoluteReg(Register arg0, int32_t arg1, Register arg2) {
  Sarxq(arg0, {.disp = arg1}, arg2);
}
constexpr void SarxqRegMemBaseDispReg(Register arg0, Register arg1_base, int32_t arg1_disp, Register arg2) {
  Sarxq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void SarxqRegMemIndexDispReg(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Sarxq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void SarxqRegMemBaseIndexDispReg(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Sarxq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void SbbqRegMemAbsolute(Register arg0, int32_t arg1) {
  Sbbq(arg0, {.disp = arg1});
}
constexpr void SbbqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Sbbq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void SbbqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Sbbq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void SbbqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Sbbq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void SbbqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Sbbq({.disp = arg0}, arg1);
}
constexpr void SbbqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Sbbq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SbbqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Sbbq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SbbqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Sbbq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SbbqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Sbbq({.disp = arg0}, arg1);
}
constexpr void SbbqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Sbbq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SbbqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Sbbq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SbbqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Sbbq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SbbqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  SbbqImm8({.disp = arg0}, arg1);
}
constexpr void SbbqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  SbbqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SbbqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  SbbqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SbbqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  SbbqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShldqMemAbsoluteRegImm(int32_t arg0, Register arg1, int8_t arg2) {
  Shldq({.disp = arg0}, arg1, arg2);
}
constexpr void ShldqMemBaseDispRegImm(Register arg0_base, int32_t arg0_disp, Register arg1, int8_t arg2) {
  Shldq({.base = arg0_base, .disp = arg0_disp}, arg1, arg2);
}
constexpr void ShldqMemIndexDispRegImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1, int8_t arg2) {
  Shldq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void ShldqMemBaseIndexDispRegImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1, int8_t arg2) {
  Shldq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void ShldqMemAbsoluteRegReg(int32_t arg0, Register arg1) {
  ShldqByCl({.disp = arg0}, arg1);
}
constexpr void ShldqMemBaseDispRegReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  ShldqByCl({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void ShldqMemIndexDispRegReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  ShldqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShldqMemBaseIndexDispRegReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  ShldqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShlqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Shlq({.disp = arg0}, arg1);
}
constexpr void ShlqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Shlq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void ShlqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Shlq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShlqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Shlq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShlqMemAbsoluteReg(int32_t arg0) {
  ShlqByCl({.disp = arg0});
}
constexpr void ShlqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  ShlqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void ShlqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShlqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShlqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShlqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShlqByOneMemAbsolute(int32_t arg0) {
  ShlqByOne({.disp = arg0});
}
constexpr void ShlqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  ShlqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void ShlqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShlqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShlqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShlqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShlxqRegMemAbsoluteReg(Register arg0, int32_t arg1, Register arg2) {
  Shlxq(arg0, {.disp = arg1}, arg2);
}
constexpr void ShlxqRegMemBaseDispReg(Register arg0, Register arg1_base, int32_t arg1_disp, Register arg2) {
  Shlxq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void ShlxqRegMemIndexDispReg(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Shlxq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void ShlxqRegMemBaseIndexDispReg(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Shlxq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void ShrdqMemAbsoluteRegImm(int32_t arg0, Register arg1, int8_t arg2) {
  Shrdq({.disp = arg0}, arg1, arg2);
}
constexpr void ShrdqMemBaseDispRegImm(Register arg0_base, int32_t arg0_disp, Register arg1, int8_t arg2) {
  Shrdq({.base = arg0_base, .disp = arg0_disp}, arg1, arg2);
}
constexpr void ShrdqMemIndexDispRegImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1, int8_t arg2) {
  Shrdq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void ShrdqMemBaseIndexDispRegImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1, int8_t arg2) {
  Shrdq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void ShrdqMemAbsoluteRegReg(int32_t arg0, Register arg1) {
  ShrdqByCl({.disp = arg0}, arg1);
}
constexpr void ShrdqMemBaseDispRegReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  ShrdqByCl({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void ShrdqMemIndexDispRegReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  ShrdqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShrdqMemBaseIndexDispRegReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  ShrdqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShrqMemAbsoluteImm(int32_t arg0, int8_t arg1) {
  Shrq({.disp = arg0}, arg1);
}
constexpr void ShrqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  Shrq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void ShrqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Shrq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShrqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  Shrq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void ShrqMemAbsoluteReg(int32_t arg0) {
  ShrqByCl({.disp = arg0});
}
constexpr void ShrqMemBaseDispReg(Register arg0_base, int32_t arg0_disp) {
  ShrqByCl({.base = arg0_base, .disp = arg0_disp});
}
constexpr void ShrqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShrqByCl({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShrqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShrqByCl({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShrqByOneMemAbsolute(int32_t arg0) {
  ShrqByOne({.disp = arg0});
}
constexpr void ShrqByOneMemBaseDisp(Register arg0_base, int32_t arg0_disp) {
  ShrqByOne({.base = arg0_base, .disp = arg0_disp});
}
constexpr void ShrqByOneMemIndexDisp(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShrqByOne({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShrqByOneMemBaseIndexDisp(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp) {
  ShrqByOne({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp});
}
constexpr void ShrxqRegMemAbsoluteReg(Register arg0, int32_t arg1, Register arg2) {
  Shrxq(arg0, {.disp = arg1}, arg2);
}
constexpr void ShrxqRegMemBaseDispReg(Register arg0, Register arg1_base, int32_t arg1_disp, Register arg2) {
  Shrxq(arg0, {.base = arg1_base, .disp = arg1_disp}, arg2);
}
constexpr void ShrxqRegMemIndexDispReg(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Shrxq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void ShrxqRegMemBaseIndexDispReg(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp, Register arg2) {
  Shrxq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp}, arg2);
}
constexpr void SubqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Subq({.disp = arg0}, arg1);
}
constexpr void SubqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Subq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SubqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Subq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SubqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Subq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SubqRegMemAbsolute(Register arg0, int32_t arg1) {
  Subq(arg0, {.disp = arg1});
}
constexpr void SubqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Subq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void SubqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Subq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void SubqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Subq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void SubqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Subq({.disp = arg0}, arg1);
}
constexpr void SubqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Subq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SubqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Subq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SubqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Subq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SubqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  SubqImm8({.disp = arg0}, arg1);
}
constexpr void SubqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  SubqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void SubqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  SubqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void SubqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  SubqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void TestqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Testq({.disp = arg0}, arg1);
}
constexpr void TestqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Testq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void TestqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Testq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void TestqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Testq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void TestqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Testq({.disp = arg0}, arg1);
}
constexpr void TestqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Testq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void TestqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Testq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void TestqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Testq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void TzcntqRegMemAbsolute(Register arg0, int32_t arg1) {
  Tzcntq(arg0, {.disp = arg1});
}
constexpr void TzcntqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Tzcntq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void TzcntqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Tzcntq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void TzcntqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Tzcntq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void VpextrqMemAbsoluteXRegImm(int32_t arg0, XMMRegister arg1, int8_t arg2) {
  Vpextrq({.disp = arg0}, arg1, arg2);
}
constexpr void VpextrqMemBaseDispXRegImm(Register arg0_base, int32_t arg0_disp, XMMRegister arg1, int8_t arg2) {
  Vpextrq({.base = arg0_base, .disp = arg0_disp}, arg1, arg2);
}
constexpr void VpextrqMemIndexDispXRegImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, XMMRegister arg1, int8_t arg2) {
  Vpextrq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void VpextrqMemBaseIndexDispXRegImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, XMMRegister arg1, int8_t arg2) {
  Vpextrq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1, arg2);
}
constexpr void VpinsrqXRegXRegMemAbsoluteImm(XMMRegister arg0, XMMRegister arg1, int32_t arg2, int8_t arg3) {
  Vpinsrq(arg0, arg1, {.disp = arg2}, arg3);
}
constexpr void VpinsrqXRegXRegMemBaseDispImm(XMMRegister arg0, XMMRegister arg1, Register arg2_base, int32_t arg2_disp, int8_t arg3) {
  Vpinsrq(arg0, arg1, {.base = arg2_base, .disp = arg2_disp}, arg3);
}
constexpr void VpinsrqXRegXRegMemIndexDispImm(XMMRegister arg0, XMMRegister arg1, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp, int8_t arg3) {
  Vpinsrq(arg0, arg1, {.index = arg2_index, .scale = arg2_scale, .disp = arg2_disp}, arg3);
}
constexpr void VpinsrqXRegXRegMemBaseIndexDispImm(XMMRegister arg0, XMMRegister arg1, Register arg2_base, Register arg2_index, ScaleFactor arg2_scale, int32_t arg2_disp, int8_t arg3) {
  Vpinsrq(arg0, arg1, {.base = arg2_base, .index = arg2_index, .scale = arg2_scale, .disp = arg2_disp}, arg3);
}
constexpr void XaddqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Xaddq({.disp = arg0}, arg1);
}
constexpr void XaddqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Xaddq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void XaddqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Xaddq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XaddqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Xaddq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XchgqRegMemAbsolute(Register arg0, int32_t arg1) {
  Xchgq(arg0, {.disp = arg1});
}
constexpr void XchgqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Xchgq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void XchgqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Xchgq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void XchgqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Xchgq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void XorqMemAbsoluteReg(int32_t arg0, Register arg1) {
  Xorq({.disp = arg0}, arg1);
}
constexpr void XorqMemBaseDispReg(Register arg0_base, int32_t arg0_disp, Register arg1) {
  Xorq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void XorqMemIndexDispReg(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Xorq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XorqMemBaseIndexDispReg(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, Register arg1) {
  Xorq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XorqRegMemAbsolute(Register arg0, int32_t arg1) {
  Xorq(arg0, {.disp = arg1});
}
constexpr void XorqRegMemBaseDisp(Register arg0, Register arg1_base, int32_t arg1_disp) {
  Xorq(arg0, {.base = arg1_base, .disp = arg1_disp});
}
constexpr void XorqRegMemIndexDisp(Register arg0, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Xorq(arg0, {.index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void XorqRegMemBaseIndexDisp(Register arg0, Register arg1_base, Register arg1_index, ScaleFactor arg1_scale, int32_t arg1_disp) {
  Xorq(arg0, {.base = arg1_base, .index = arg1_index, .scale = arg1_scale, .disp = arg1_disp});
}
constexpr void XorqMemAbsoluteImm(int32_t arg0, int32_t arg1) {
  Xorq({.disp = arg0}, arg1);
}
constexpr void XorqMemBaseDispImm(Register arg0_base, int32_t arg0_disp, int32_t arg1) {
  Xorq({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void XorqMemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Xorq({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XorqMemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int32_t arg1) {
  Xorq({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XorqImm8MemAbsoluteImm(int32_t arg0, int8_t arg1) {
  XorqImm8({.disp = arg0}, arg1);
}
constexpr void XorqImm8MemBaseDispImm(Register arg0_base, int32_t arg0_disp, int8_t arg1) {
  XorqImm8({.base = arg0_base, .disp = arg0_disp}, arg1);
}
constexpr void XorqImm8MemIndexDispImm(Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  XorqImm8({.index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
constexpr void XorqImm8MemBaseIndexDispImm(Register arg0_base, Register arg0_index, ScaleFactor arg0_scale, int32_t arg0_disp, int8_t arg1) {
  XorqImm8({.base = arg0_base, .index = arg0_index, .scale = arg0_scale, .disp = arg0_disp}, arg1);
}
