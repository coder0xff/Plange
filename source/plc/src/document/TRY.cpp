// This file was generated using Parlex's cpp_generator

#include "TRY.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
plc::TRY::field_6_t_1_t plc::TRY::field_6_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_6_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::TRY::field_7_t_1_t plc::TRY::field_7_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_7_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::TRY plc::TRY::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TRY(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_5)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_6)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_7)>::build(*children[0], n.children[0])
);
}

