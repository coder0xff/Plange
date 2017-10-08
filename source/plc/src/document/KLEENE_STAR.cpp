// This file was generated using Parlex's cpp_generator

#include "KLEENE_STAR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
plc::KLEENE_STAR plc::KLEENE_STAR::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return KLEENE_STAR(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

