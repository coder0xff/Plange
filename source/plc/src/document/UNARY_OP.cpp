// This file was generated using Parlex's cpp_generator

#include "UNARY_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ALLOCATION.hpp"
#include "CARDINALITY.hpp"
#include "KLEENE_STAR.hpp"
#include "UNARY_ARITHMETIC_OP.hpp"
#include "UNARY_LOGICAL_OP.hpp"
#include "UNARY_OP.hpp"

namespace plc {

UNARY_OP UNARY_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return UNARY_OP(parlex::details::document::element<UNARY_OP_base>::build(b, n));
}

} // namespace plc
