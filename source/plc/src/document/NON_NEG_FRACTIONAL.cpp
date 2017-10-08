// This file was generated using Parlex's cpp_generator

#include "NON_NEG_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_NEG_FRACTIONAL.hpp"

namespace plc {

NON_NEG_FRACTIONAL NON_NEG_FRACTIONAL::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return NON_NEG_FRACTIONAL(parlex::details::document::element<NON_NEG_FRACTIONAL_base>::build(b, n));
}

} // namespace plc
plc::NON_NEG_FRACTIONAL_1_t plc::NON_NEG_FRACTIONAL_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return NON_NEG_FRACTIONAL_1_t(
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::NON_NEG_FRACTIONAL_2_t plc::NON_NEG_FRACTIONAL_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return NON_NEG_FRACTIONAL_2_t(
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

