// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SET_COMPREHENSION_HPP
#define INCLUDED_SET_COMPREHENSION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct SET_COMPREHENSION {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;
	std::vector<erased<IC>> field_6;

	SET_COMPREHENSION(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2,
		std::vector<erased<IC>> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5,
		std::vector<erased<IC>> const & field_6
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}
};



#endif //INCLUDED_SET_COMPREHENSION_HPP
