// This file was generated using Parlex's cpp_generator

#include "BINARY_ARITHMETIC_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ADDITION.hpp"
#include "ADD_SUB.hpp"
#include "DIVISION.hpp"
#include "EXPONENTIATION.hpp"
#include "INTEGER_DIVISION.hpp"
#include "MODULATION.hpp"
#include "MULTIPLICATIVE_OP.hpp"
#include "SHIFTL.hpp"
#include "SHIFTR.hpp"
#include "SUBTRACTION.hpp"
#include "BINARY_ARITHMETIC_OP.hpp"

namespace plc {

BINARY_ARITHMETIC_OP BINARY_ARITHMETIC_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return BINARY_ARITHMETIC_OP(parlex::details::document::element<BINARY_ARITHMETIC_OP_base>::build(b, n));
}

} // namespace plc
