// This file was generated using Parlex's cpp_generator

#include "ADD_SUB.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "parlex/details/document.hpp"
#include "plange_grammar.hpp"

plc::ADD_SUB plc::ADD_SUB::build(parlex::details::ast_node const & n)
{
	static auto const & behavior = plange_grammar().ADD_SUB.get_behavior();
	static auto const & children = behavior.get_children();
	return ADD_SUB(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[1], n.children[1]),
		parlex::details::document::element<decltype(field_3)>::build(*children[2], n.children[2]),
		parlex::details::document::element<decltype(field_4)>::build(*children[3], n.children[3]),
		parlex::details::document::element<decltype(field_5)>::build(*children[4], n.children[4])
	);
}
