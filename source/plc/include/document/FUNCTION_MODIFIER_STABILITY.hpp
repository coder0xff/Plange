// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
#define INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct FUNCTION_MODIFIER_1;
struct ICR;

struct FUNCTION_MODIFIER_STABILITY {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> stability;
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_1>
	>> field_1;

	FUNCTION_MODIFIER_STABILITY(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & stability,
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_1>
		>> const & field_1
	) : stability(stability), field_1(field_1) {}
};



#endif //INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
