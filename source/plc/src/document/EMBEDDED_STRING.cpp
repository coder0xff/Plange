// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EMBEDDED_STRING_INTERIOR.hpp"
plc::EMBEDDED_STRING plc::EMBEDDED_STRING::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return EMBEDDED_STRING(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

