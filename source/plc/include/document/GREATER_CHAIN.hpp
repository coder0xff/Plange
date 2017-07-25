// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_HPP
#define INCLUDED_GREATER_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct GREATER_CHAIN_LOOP;
struct IC;

struct GREATER_CHAIN {
	erased<EXPRESSION> EXPRESSION;
	std::vector<erased<IC>> field_1;
	erased<GREATER_CHAIN_LOOP> GREATER_CHAIN_LOOP;

	GREATER_CHAIN(
		erased<EXPRESSION> const & EXPRESSION,
		std::vector<erased<IC>> const & field_1,
		erased<GREATER_CHAIN_LOOP> const & GREATER_CHAIN_LOOP
	) : EXPRESSION(EXPRESSION), field_1(field_1), GREATER_CHAIN_LOOP(GREATER_CHAIN_LOOP) {}
};



#endif //INCLUDED_GREATER_CHAIN_HPP
