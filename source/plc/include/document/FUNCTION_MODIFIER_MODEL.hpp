// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
#define INCLUDED_FUNCTION_MODIFIER_MODEL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct ICR;

struct FUNCTION_MODIFIER_MODEL {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		std::integral_constant<int, 2>
	> model;
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
	>> field_1;

	FUNCTION_MODIFIER_MODEL(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			std::integral_constant<int, 2>
		> const & model,
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
		>> const & field_1
	) : model(model), field_1(field_1) {}
};



#endif //INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
