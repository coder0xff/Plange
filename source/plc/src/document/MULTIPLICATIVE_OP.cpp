// This file was generated using Parlex's cpp_generator

#include "MULTIPLICATIVE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "CROSS_PRODUCT.hpp"
#include "DOT_PRODUCT.hpp"
#include "MULTIPLICATION.hpp"
#include "MULTIPLICATIVE_OP.hpp"

namespace plc {

MULTIPLICATIVE_OP MULTIPLICATIVE_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return MULTIPLICATIVE_OP(parlex::details::document::element<MULTIPLICATIVE_OP_base>::build(b, n));
}

} // namespace plc
