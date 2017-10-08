// This file was generated using Parlex's cpp_generator

#include "GREATER_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "GREATER_CHAIN_LOOP.hpp"
#include "IC.hpp"
plc::GREATER_CHAIN plc::GREATER_CHAIN::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return GREATER_CHAIN(
		parlex::details::document::element<decltype(expression)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(greater_chain_loop)>::build(*children[0], n.children[0])
);
}

