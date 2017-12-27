// This file was generated using Parlex's cpp_generator

#include "STATEMENT_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "STATEMENT.hpp"

#include "STATEMENT_SCOPE.hpp"

namespace plc {

STATEMENT_SCOPE STATEMENT_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATEMENT_SCOPE(parlex::detail::document::element<STATEMENT_SCOPE_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::STATEMENT_SCOPE::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STATEMENT_SCOPE));
	return result;
}
