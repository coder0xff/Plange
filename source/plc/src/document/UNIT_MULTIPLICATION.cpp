// This file was generated using Parlex's cpp_generator

#include "UNIT_MULTIPLICATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSION.hpp"
plc::UNIT_MULTIPLICATION plc::UNIT_MULTIPLICATION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return UNIT_MULTIPLICATION(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

