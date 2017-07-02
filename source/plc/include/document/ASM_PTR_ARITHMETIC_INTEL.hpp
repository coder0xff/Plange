// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
struct ASM_PTR_ARITHMETIC_INTEL {
	std::optional<std::tuple<
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>,
			std::std::integral_constant<int, 2>,
			std::std::integral_constant<int, 3>
		>
	>> field_1;
	std::optional<std::tuple<
		ASM_IDENTIFIER
	>> field_2;
	ASM_IDENTIFIER field_3;
	std::optional<std::tuple<
		ASM_IDENTIFIER,
		std::optional<std::tuple<
			NON_NEG_NON_FRACTIONAL
		>>
	>> field_4;
	std::optional<std::tuple<
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		NON_NEG_INTEGER
	>> field_5;
};

#endif //INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP