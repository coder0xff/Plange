// This file was generated using Parlex's cpp_generator

#include "ASM_EXPRESSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_IDENTIFIER.hpp"
#include "ASM_PTR_ARITHMETIC_ATT.hpp"
#include "ASM_PTR_ARITHMETIC_INTEL.hpp"
#include "NON_FRACTIONAL.hpp"

#include "ASM_EXPRESSION.hpp"

namespace plc {

ASM_EXPRESSION ASM_EXPRESSION::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_EXPRESSION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_EXPRESSION(parlex::details::document::element<ASM_EXPRESSION_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::ASM_EXPRESSION::recognizer() {
	return plange_grammar::get().ASM_EXPRESSION.get_recognizer();
}
