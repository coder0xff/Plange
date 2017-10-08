// This file was generated using Parlex's cpp_generator

#include "PARAMETER_NATURAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "PARAMETER_NATURAL.hpp"

namespace plc {

PARAMETER_NATURAL PARAMETER_NATURAL::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return PARAMETER_NATURAL(parlex::details::document::element<PARAMETER_NATURAL_base>::build(b, n));
}

} // namespace plc
plc::PARAMETER_NATURAL_1_t::field_1_t_1_t plc::PARAMETER_NATURAL_1_t::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::PARAMETER_NATURAL_1_t plc::PARAMETER_NATURAL_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return PARAMETER_NATURAL_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::PARAMETER_NATURAL_2_t::field_1_t_1_t plc::PARAMETER_NATURAL_2_t::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::PARAMETER_NATURAL_2_t plc::PARAMETER_NATURAL_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return PARAMETER_NATURAL_2_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_5)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_6)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_7)>::build(*children[0], n.children[0])
);
}

