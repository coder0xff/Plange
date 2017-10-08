// This file was generated using Parlex's cpp_generator

#include "BINARY_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BINARY_ARITHMETIC_OP.hpp"
#include "BINARY_COLLECTION_OP.hpp"
#include "BINARY_LOGICAL_OP.hpp"
#include "BITWISE_OP.hpp"
#include "CONSTRUCTIVE_OP.hpp"
#include "RELATIONAL_OP.hpp"
#include "BINARY_OP.hpp"

namespace plc {

BINARY_OP BINARY_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return BINARY_OP(parlex::details::document::element<BINARY_OP_base>::build(b, n));
}

} // namespace plc
