// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASSIGNMENT_CHAIN.hpp"
#include "DECLARATION.hpp"
#include "DEFINITION.hpp"
#include "IC.hpp"
#include "TYPE_CONSTRAINT_CHAIN.hpp"
plc::TYPE_CONSTRAINT_CHAIN::field_2_t_1_t plc::TYPE_CONSTRAINT_CHAIN::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::TYPE_CONSTRAINT_CHAIN plc::TYPE_CONSTRAINT_CHAIN::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TYPE_CONSTRAINT_CHAIN(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

