// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LOCK_HPP
#define INCLUDED_LOCK_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct BLOCK;
struct IC;
struct PARENTHETICAL;

struct LOCK {
	std::vector<erased<IC>> field_1;
	erased<PARENTHETICAL> field_2;
	std::vector<erased<IC>> field_3;
	erased<BLOCK> field_4;

	LOCK(
		std::vector<erased<IC>> const & field_1,
		erased<PARENTHETICAL> const & field_2,
		std::vector<erased<IC>> const & field_3,
		erased<BLOCK> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}
};



#endif //INCLUDED_LOCK_HPP
