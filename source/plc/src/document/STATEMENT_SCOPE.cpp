// This file was generated using Parlex's cpp_generator

#include "STATEMENT_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IC.hpp"
#include "STATEMENT.hpp"

#include "STATEMENT_SCOPE.hpp"

namespace plc {

STATEMENT_SCOPE STATEMENT_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().STATEMENT_SCOPE.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATEMENT_SCOPE(parlex::detail::document::element<STATEMENT_SCOPE_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::STATEMENT_SCOPE::recognizer() {
	return plange_grammar::get().STATEMENT_SCOPE.get_recognizer();
}
