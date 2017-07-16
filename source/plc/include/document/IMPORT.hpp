// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPORT_HPP
#define INCLUDED_IMPORT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct IMPORT {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;

	IMPORT(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_IMPORT_HPP
