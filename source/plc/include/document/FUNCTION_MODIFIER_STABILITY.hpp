// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
#define INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
struct FUNCTION_MODIFIER_STABILITY {
	std::optional<std::tuple<
		ICR,
		FUNCTION_MODIFIER_1
	>> field_1;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> stability;
};

#endif //INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP