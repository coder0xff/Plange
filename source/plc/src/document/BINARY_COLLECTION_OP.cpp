// This file was generated using Parlex's cpp_generator

#include "BINARY_COLLECTION_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BIJECTION.hpp"
#include "INTERSECTION.hpp"
#include "SYMMETRIC_DIFFERENCE.hpp"
#include "UNION.hpp"
#include "BINARY_COLLECTION_OP.hpp"

namespace plc {

BINARY_COLLECTION_OP BINARY_COLLECTION_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return BINARY_COLLECTION_OP(parlex::details::document::element<BINARY_COLLECTION_OP_base>::build(b, n));
}

} // namespace plc
