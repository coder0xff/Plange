// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_COMMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EMBEDDED_COMMENT_INTERIOR.hpp"
plc::EMBEDDED_COMMENT plc::EMBEDDED_COMMENT::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return EMBEDDED_COMMENT(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

