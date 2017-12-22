// This file was generated using Parlex's cpp_generator

#include "ASM_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ASM_STATEMENT.hpp"
#include "IC.hpp"

#include "ASM_SCOPE.hpp"

namespace plc {

ASM_SCOPE ASM_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_SCOPE.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_SCOPE(parlex::detail::document::element<ASM_SCOPE_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::ASM_SCOPE::recognizer() {
	return plange_grammar::get().ASM_SCOPE.get_recognizer();
}
