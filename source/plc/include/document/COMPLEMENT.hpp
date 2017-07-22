// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMPLEMENT_HPP
#define INCLUDED_COMPLEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct COMPLEMENT {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;

	COMPLEMENT(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_COMPLEMENT_HPP
