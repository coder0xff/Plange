// This file was generated using Parlex's cpp_generator

#include "HEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::HEX plc::HEX::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return HEX(
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

