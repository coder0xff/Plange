// This file was generated using Parlex's cpp_generator

#include "ASM_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASM_STATEMENT.hpp"
#include "IC.hpp"

#include "ASM_SCOPE.hpp"

namespace plc {

ASM_SCOPE ASM_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_SCOPE(parlex::detail::document::element<ASM_SCOPE_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::ASM_SCOPE::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_SCOPE));
	return result;
}
