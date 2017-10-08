// This file was generated using Parlex's cpp_generator

#include "EQUALITY_CHAIN_LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EQUALITY_CHAIN_LOOP.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
plc::EQUALITY_CHAIN_LOOP::field_2_t_1_t plc::EQUALITY_CHAIN_LOOP::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(equality_chain_loop)>::build(*children[0], n.children[0])
);
}

plc::EQUALITY_CHAIN_LOOP plc::EQUALITY_CHAIN_LOOP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return EQUALITY_CHAIN_LOOP(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(expression)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

