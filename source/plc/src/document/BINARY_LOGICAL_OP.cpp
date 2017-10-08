// This file was generated using Parlex's cpp_generator

#include "BINARY_LOGICAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "AND.hpp"
#include "IFF.hpp"
#include "IMPLICATION.hpp"
#include "MAPS_TO.hpp"
#include "NAND.hpp"
#include "NOR.hpp"
#include "OR.hpp"
#include "XOR.hpp"
#include "BINARY_LOGICAL_OP.hpp"

namespace plc {

BINARY_LOGICAL_OP BINARY_LOGICAL_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return BINARY_LOGICAL_OP(parlex::details::document::element<BINARY_LOGICAL_OP_base>::build(b, n));
}

} // namespace plc
