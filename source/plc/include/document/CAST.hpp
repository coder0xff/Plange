// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CAST_HPP
#define INCLUDED_CAST_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct CAST {
	erased<PARENTHETICAL> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;

	CAST(
		erased<PARENTHETICAL> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}
};



#endif //INCLUDED_CAST_HPP
