// This file was generated using Parlex's cpp_generator

#include "INHERITANCE_ITEM_PREFIX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ICR.hpp"
#include "VISIBILITY_MODIFIER.hpp"
plc::INHERITANCE_ITEM_PREFIX::field_1_t_2_t plc::INHERITANCE_ITEM_PREFIX::field_1_t_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_2_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::INHERITANCE_ITEM_PREFIX plc::INHERITANCE_ITEM_PREFIX::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return INHERITANCE_ITEM_PREFIX(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

