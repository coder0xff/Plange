// This file was generated using Parlex's cpp_generator

#include "FUNCTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BLOCK.hpp"
#include "FUNCTION_MODIFIER_0.hpp"
#include "IC.hpp"
#include "PARAMETER.hpp"
plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(parameter)>::build(*children[0], n.children[0])
);
}

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(parameter)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::FUNCTION::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::FUNCTION::field_2_t_1_t plc::FUNCTION::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::FUNCTION plc::FUNCTION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return FUNCTION(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(block)>::build(*children[0], n.children[0])
);
}

