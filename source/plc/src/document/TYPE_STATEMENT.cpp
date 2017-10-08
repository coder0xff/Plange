// This file was generated using Parlex's cpp_generator

#include "TYPE_STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "STATEMENT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "TYPE_STATEMENT.hpp"

namespace plc {

TYPE_STATEMENT TYPE_STATEMENT::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return TYPE_STATEMENT(parlex::details::document::element<TYPE_STATEMENT_base>::build(b, n));
}

} // namespace plc
plc::TYPE_STATEMENT_1_t plc::TYPE_STATEMENT_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return TYPE_STATEMENT_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

