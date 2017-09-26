// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_HPP
#define INCLUDED_EQUALITY_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN {
	erased<EXPRESSION> expression;
	std::vector<erased<IC>> field_1;
	erased<EQUALITY_CHAIN_LOOP> equality_chain_loop;


	EQUALITY_CHAIN(
		erased<EXPRESSION> const & expression,
		std::vector<erased<IC>> const & field_1,
		erased<EQUALITY_CHAIN_LOOP> const & equality_chain_loop
	) : expression(expression), field_1(field_1), equality_chain_loop(equality_chain_loop) {}

	static std::optional<EQUALITY_CHAIN> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_EQUALITY_CHAIN_HPP
