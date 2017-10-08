// This file was generated using Parlex's cpp_generator

#include "TUPLE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
plc::TUPLE::field_3_t_1_t plc::TUPLE::field_3_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_3_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::TUPLE plc::TUPLE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TUPLE(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0])
);
}

