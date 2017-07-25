// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FACTORIAL_HPP
#define INCLUDED_FACTORIAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct FACTORIAL {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;

	FACTORIAL(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_FACTORIAL_HPP
