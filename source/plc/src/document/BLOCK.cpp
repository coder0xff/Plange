// This file was generated using Parlex's cpp_generator

#include "BLOCK.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "STATEMENT_SCOPE.hpp"
plc::BLOCK plc::BLOCK::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return BLOCK(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

