// This file was generated using Parlex's cpp_generator

#include "CONTINUE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "ICR.hpp"
#include "IDENTIFIER.hpp"
plc::CONTINUE::field_1_t_1_t_1_t plc::CONTINUE::field_1_t_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(expression)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::CONTINUE::field_1_t_1_t_2_t plc::CONTINUE::field_1_t_1_t_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t_2_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(identifier)>::build(*children[0], n.children[0])
);
}

plc::CONTINUE plc::CONTINUE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return CONTINUE(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

