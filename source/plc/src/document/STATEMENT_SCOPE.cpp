// This file was generated using Parlex's cpp_generator

#include "STATEMENT_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "STATEMENT.hpp"

#include "STATEMENT_SCOPE.hpp"

namespace plc {

STATEMENT_SCOPE STATEMENT_SCOPE::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().STATEMENT_SCOPE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATEMENT_SCOPE(parlex::details::document::element<STATEMENT_SCOPE_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::STATEMENT_SCOPE::recognizer() {
	return plange_grammar::get().STATEMENT_SCOPE.get_recognizer();
}
