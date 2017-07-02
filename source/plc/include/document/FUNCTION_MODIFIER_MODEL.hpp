// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
#define INCLUDED_FUNCTION_MODIFIER_MODEL_HPP

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct ICR;

struct FUNCTION_MODIFIER_MODEL {
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
	>> field_1;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>,
		std::std::integral_constant<int, 2>
	> model;
};



#endif //INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
