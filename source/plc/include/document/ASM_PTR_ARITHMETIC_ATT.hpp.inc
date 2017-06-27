// This file was generated using parlex's cpp_generator

typedef std::variant<
	std::tuple<
		ASM_IDENTIFIER,
		NON_FRACTIONAL
	>,
	std::tuple<
		ASM_IDENTIFIER,
		NON_FRACTIONAL,
		ASM_PTR_ARITHMETIC_ATT_REG
	>,
	std::tuple<
		NON_FRACTIONAL,
		ASM_PTR_ARITHMETIC_ATT_REG
	>
> ASM_PTR_ARITHMETIC_ATT;