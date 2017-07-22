// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_PACK_HPP
#define INCLUDED_ARGUMENT_PACK_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct ARGUMENT_PACK {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;

	ARGUMENT_PACK(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_ARGUMENT_PACK_HPP
