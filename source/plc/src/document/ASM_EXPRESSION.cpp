// This file was generated using Parlex's cpp_generator

#include "ASM_EXPRESSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASM_IDENTIFIER.hpp"
#include "ASM_PTR_ARITHMETIC_ATT.hpp"
#include "ASM_PTR_ARITHMETIC_INTEL.hpp"
#include "NON_FRACTIONAL.hpp"

#include "ASM_EXPRESSION.hpp"

namespace plc {

ASM_EXPRESSION ASM_EXPRESSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_EXPRESSION(parlex::detail::document::element<ASM_EXPRESSION_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::ASM_EXPRESSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_EXPRESSION));
	return result;
}
