// This file was generated using Parlex's cpp_generator

#include "NEAREST_INTEGER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "NEAREST_INTEGER.hpp"

namespace plc {

NEAREST_INTEGER NEAREST_INTEGER::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return NEAREST_INTEGER(parlex::details::document::element<NEAREST_INTEGER_base>::build(b, n));
}

} // namespace plc
plc::NEAREST_INTEGER_1_t plc::NEAREST_INTEGER_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return NEAREST_INTEGER_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::NEAREST_INTEGER_2_t plc::NEAREST_INTEGER_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return NEAREST_INTEGER_2_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

