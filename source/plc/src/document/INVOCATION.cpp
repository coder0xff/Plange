// This file was generated using Parlex's cpp_generator

#include "INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ARRAY_INVOCATION.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "TYPE_INVOCATION.hpp"

#include "INVOCATION.hpp"

namespace plc {

INVOCATION INVOCATION::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().INVOCATION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return INVOCATION(parlex::details::document::element<INVOCATION_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::INVOCATION::recognizer() {
	return plange_grammar::get().INVOCATION.get_recognizer();
}
