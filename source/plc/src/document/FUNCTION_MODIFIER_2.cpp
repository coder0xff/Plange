// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_2.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_3.hpp"
#include "FUNCTION_MODIFIER_ATOMIC.hpp"
#include "FUNCTION_MODIFIER_2.hpp"

namespace plc {

FUNCTION_MODIFIER_2 FUNCTION_MODIFIER_2::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return FUNCTION_MODIFIER_2(parlex::details::document::element<FUNCTION_MODIFIER_2_base>::build(b, n));
}

} // namespace plc
