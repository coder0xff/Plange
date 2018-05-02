// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_HPP
#define INCLUDED_GREATER_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct GREATER_CHAIN_LOOP;
struct IC;

struct GREATER_CHAIN {
	erased<EXPRESSION> expression;
	
	std::vector<erased<IC>> field_1;
	
	erased<GREATER_CHAIN_LOOP> greater_chain_loop;
	


	explicit GREATER_CHAIN(
		erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_1, erased<GREATER_CHAIN_LOOP> && greater_chain_loop) : expression(std::move(expression)), field_1(std::move(field_1)), greater_chain_loop(std::move(greater_chain_loop)) {}

	GREATER_CHAIN(GREATER_CHAIN const & other) = default;
	GREATER_CHAIN(GREATER_CHAIN && move) = default;

	static GREATER_CHAIN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_GREATER_CHAIN_HPP
