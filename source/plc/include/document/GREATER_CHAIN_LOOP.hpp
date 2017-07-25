// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_LOOP_HPP
#define INCLUDED_GREATER_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct GREATER_CHAIN_LOOP;
struct IC;

struct GREATER_CHAIN_LOOP {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		std::integral_constant<int, 2>,
		std::integral_constant<int, 3>
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> EXPRESSION;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<GREATER_CHAIN_LOOP>
	>> field_3;

	GREATER_CHAIN_LOOP(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			std::integral_constant<int, 2>,
			std::integral_constant<int, 3>
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & EXPRESSION,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<GREATER_CHAIN_LOOP>
		>> const & field_3
	) : field_1(field_1), field_2(field_2), EXPRESSION(EXPRESSION), field_3(field_3) {}
};



#endif //INCLUDED_GREATER_CHAIN_LOOP_HPP
