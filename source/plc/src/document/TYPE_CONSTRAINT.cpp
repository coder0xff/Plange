// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "TYPE_CONSTRAINT_CHAIN.hpp"
#include "TYPE_CONSTRAINT_HEAD.hpp"
plc::TYPE_CONSTRAINT plc::TYPE_CONSTRAINT::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TYPE_CONSTRAINT(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

