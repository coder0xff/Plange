// This file was generated using Parlex's cpp_generator

#include "RELATIONAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "CASTS.hpp"
#include "DOWNCASTS.hpp"
#include "EXACTLY.hpp"
#include "IMPLEMENTS.hpp"
#include "INEQUALITY.hpp"
#include "INHERITS.hpp"
#include "IS.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"
#include "UPCASTS.hpp"
#include "RELATIONAL_OP.hpp"

namespace plc {

RELATIONAL_OP RELATIONAL_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return RELATIONAL_OP(parlex::details::document::element<RELATIONAL_OP_base>::build(b, n));
}

} // namespace plc
