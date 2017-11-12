// This file was generated using Parlex's cpp_generator

#include "ASM_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_STATEMENT.hpp"
#include "IC.hpp"

#include "ASM_SCOPE.hpp"

namespace plc {

ASM_SCOPE ASM_SCOPE::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_SCOPE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_SCOPE(parlex::details::document::element<ASM_SCOPE_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::ASM_SCOPE::recognizer() {
	return plange_grammar::get().ASM_SCOPE.get_recognizer();
}
