// This file was generated using Parlex's cpp_generator

#include "TIME.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::TIME::field_8_t_1_t plc::TIME::field_8_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_8_t_1_t(
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::TIME::field_9_t_1_t_1_t::field_4_t_1_t plc::TIME::field_9_t_1_t_1_t::field_4_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_4_t_1_t(
);
}

plc::TIME::field_9_t_1_t_1_t plc::TIME::field_9_t_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_9_t_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0])
);
}

plc::TIME plc::TIME::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TIME(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_8)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_9)>::build(*children[0], n.children[0])
);
}

