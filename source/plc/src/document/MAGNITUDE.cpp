// This file was generated using Parlex's cpp_generator

#include "MAGNITUDE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
plc::MAGNITUDE plc::MAGNITUDE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return MAGNITUDE(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

