// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DELTA_HPP
#define INCLUDED_DELTA_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct WHOLE_NUMBER;

struct DELTA {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_1;
	std::optional<std::tuple<
		erased<WHOLE_NUMBER>
	>> field_2;
	erased<EXPRESSION> EXPRESSION;

	DELTA(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_1,
		std::optional<std::tuple<
			erased<WHOLE_NUMBER>
		>> const & field_2,
		erased<EXPRESSION> const & EXPRESSION
	) : field_1(field_1), field_2(field_2), EXPRESSION(EXPRESSION) {}
};



#endif //INCLUDED_DELTA_HPP
