// This file was generated using Parlex's cpp_generator

#include "USING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BLOCK.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
plc::USING plc::USING::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return USING(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_5)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_6)>::build(*children[0], n.children[0])
);
}

