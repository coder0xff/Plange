// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_ATOMIC.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_3.hpp"
#include "ICR.hpp"
plc::FUNCTION_MODIFIER_ATOMIC::field_1_t_1_t plc::FUNCTION_MODIFIER_ATOMIC::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::FUNCTION_MODIFIER_ATOMIC plc::FUNCTION_MODIFIER_ATOMIC::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return FUNCTION_MODIFIER_ATOMIC(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

