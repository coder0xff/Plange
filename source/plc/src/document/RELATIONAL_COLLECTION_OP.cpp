// This file was generated using Parlex's cpp_generator

#include "RELATIONAL_COLLECTION_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "HAS.hpp"
#include "IN.hpp"
#include "NOT_HAS.hpp"
#include "NOT_IN.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"

namespace plc {

RELATIONAL_COLLECTION_OP RELATIONAL_COLLECTION_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return RELATIONAL_COLLECTION_OP(parlex::details::document::element<RELATIONAL_COLLECTION_OP_base>::build(b, n));
}

} // namespace plc
