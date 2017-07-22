// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct VOLATILE_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::vector<erased<IC>> field_4;

	VOLATILE_TYPE_DEREFERENCE(
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3,
		std::vector<erased<IC>> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}
};



#endif //INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
