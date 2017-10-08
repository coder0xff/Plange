// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_HEAD.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ATTRIBUTE.hpp"
#include "IC.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "VOLATILE_IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "VOLATILE_TYPE_DEREFERENCE.hpp"
#include "XML_DOC_STRING.hpp"
plc::TYPE_CONSTRAINT_HEAD::field_1_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(xml_doc_string)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::TYPE_CONSTRAINT_HEAD::field_2_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::TYPE_CONSTRAINT_HEAD::field_3_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_3_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_3_t_1_t(
		parlex::details::document::element<decltype(visibility_modifier)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::TYPE_CONSTRAINT_HEAD::field_4_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_4_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_4_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::TYPE_CONSTRAINT_HEAD::field_5_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_5_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_5_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::TYPE_CONSTRAINT_HEAD plc::TYPE_CONSTRAINT_HEAD::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TYPE_CONSTRAINT_HEAD(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_5)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(type_dereference)>::build(*children[0], n.children[0])
);
}

