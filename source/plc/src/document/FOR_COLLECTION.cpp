// This file was generated using Parlex's cpp_generator

#include "FOR_COLLECTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"
plc::FOR_COLLECTION::declaration::field_1_t_1_t plc::FOR_COLLECTION::declaration::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::FOR_COLLECTION::declaration plc::FOR_COLLECTION::declaration::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return declaration(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::FOR_COLLECTION plc::FOR_COLLECTION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return FOR_COLLECTION(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_5)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_6)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(collection)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_7)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_8)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(invoke)>::build(*children[0], n.children[0])
);
}

