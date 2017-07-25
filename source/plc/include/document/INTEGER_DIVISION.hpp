// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INTEGER_DIVISION_HPP
#define INCLUDED_INTEGER_DIVISION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct INTEGER_DIVISION {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> field_4;

	INTEGER_DIVISION(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::vector<erased<IC>> const & field_3,
		erased<EXPRESSION> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}
};



#endif //INCLUDED_INTEGER_DIVISION_HPP
