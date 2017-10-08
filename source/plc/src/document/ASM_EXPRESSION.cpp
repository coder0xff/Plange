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

ASM_EXPRESSION ASM_EXPRESSION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return ASM_EXPRESSION(parlex::details::document::element<ASM_EXPRESSION_base>::build(b, n));
}

} // namespace plc
