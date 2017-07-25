// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_HPP
#define INCLUDED_EQUALITY_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN {
	erased<EXPRESSION> EXPRESSION;
	std::vector<erased<IC>> field_1;
	erased<EQUALITY_CHAIN_LOOP> EQUALITY_CHAIN_LOOP;

	EQUALITY_CHAIN(
		erased<EXPRESSION> const & EXPRESSION,
		std::vector<erased<IC>> const & field_1,
		erased<EQUALITY_CHAIN_LOOP> const & EQUALITY_CHAIN_LOOP
	) : EXPRESSION(EXPRESSION), field_1(field_1), EQUALITY_CHAIN_LOOP(EQUALITY_CHAIN_LOOP) {}
};



#endif //INCLUDED_EQUALITY_CHAIN_HPP
