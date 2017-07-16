// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXISTS_HPP
#define INCLUDED_EXISTS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct EXISTS {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;

	EXISTS(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}
};



#endif //INCLUDED_EXISTS_HPP
