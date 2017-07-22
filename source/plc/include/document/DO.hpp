// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DO_HPP
#define INCLUDED_DO_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct DO {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> EXPRESSION;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		>,
		std::vector<erased<IC>>,
		erased<PARENTHETICAL>
	>> field_2;

	DO(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & EXPRESSION,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::variant<
				std::integral_constant<int, 0>,
				std::integral_constant<int, 1>
			>,
			std::vector<erased<IC>>,
			erased<PARENTHETICAL>
		>> const & field_2
	) : field_1(field_1), EXPRESSION(EXPRESSION), field_2(field_2) {}
};



#endif //INCLUDED_DO_HPP
