// This file was generated using Parlex's cpp_generator

#include "DEFINITION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "XML_DOC_STRING.hpp"
plc::DEFINITION::field_1_t_1_t plc::DEFINITION::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(xml_doc_string)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::DEFINITION plc::DEFINITION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return DEFINITION(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(identifier)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(expression)>::build(*children[0], n.children[0])
);
}

