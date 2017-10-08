// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSION.hpp"
#include "NON_NEG_NUMBER.hpp"
plc::DIMENSIONAL_NUMBER plc::DIMENSIONAL_NUMBER::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return DIMENSIONAL_NUMBER(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

