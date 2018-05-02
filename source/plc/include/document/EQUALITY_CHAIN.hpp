// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_HPP
#define INCLUDED_EQUALITY_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN {
	erased<EXPRESSION> expression;
	
	std::vector<erased<IC>> field_1;
	
	erased<EQUALITY_CHAIN_LOOP> equality_chain_loop;
	


	explicit EQUALITY_CHAIN(
		erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_1, erased<EQUALITY_CHAIN_LOOP> && equality_chain_loop) : expression(std::move(expression)), field_1(std::move(field_1)), equality_chain_loop(std::move(equality_chain_loop)) {}

	EQUALITY_CHAIN(EQUALITY_CHAIN const & other) = default;
	EQUALITY_CHAIN(EQUALITY_CHAIN && move) = default;

	static EQUALITY_CHAIN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EQUALITY_CHAIN_HPP
