// This file was generated using Parlex's cpp_generator

#include "BITWISE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BIT_AND.hpp"
#include "BIT_OR.hpp"
#include "BIT_XOR.hpp"
#include "BITWISE_OP.hpp"

namespace plc {

BITWISE_OP BITWISE_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return BITWISE_OP(parlex::details::document::element<BITWISE_OP_base>::build(b, n));
}

} // namespace plc
