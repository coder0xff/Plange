// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_ACCESS_HPP
#define INCLUDED_MEMBER_ACCESS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct IDENTIFIER;

struct MEMBER_ACCESS {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<IDENTIFIER> field_4;

	MEMBER_ACCESS(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::vector<erased<IC>> const & field_3,
		erased<IDENTIFIER> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}
};



#endif //INCLUDED_MEMBER_ACCESS_HPP
