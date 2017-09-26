// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_HPP
#define INCLUDED_GREATER_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct GREATER_CHAIN_LOOP;
struct IC;

struct GREATER_CHAIN {
	erased<EXPRESSION> expression;
	std::vector<erased<IC>> field_1;
	erased<GREATER_CHAIN_LOOP> greater_chain_loop;


	GREATER_CHAIN(
		erased<EXPRESSION> const & expression,
		std::vector<erased<IC>> const & field_1,
		erased<GREATER_CHAIN_LOOP> const & greater_chain_loop
	) : expression(expression), field_1(field_1), greater_chain_loop(greater_chain_loop) {}

	static std::optional<GREATER_CHAIN> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_GREATER_CHAIN_HPP
