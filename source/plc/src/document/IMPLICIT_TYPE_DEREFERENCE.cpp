// This file was generated using Parlex's cpp_generator

#include "IMPLICIT_TYPE_DEREFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
plc::IMPLICIT_TYPE_DEREFERENCE plc::IMPLICIT_TYPE_DEREFERENCE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return IMPLICIT_TYPE_DEREFERENCE(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

