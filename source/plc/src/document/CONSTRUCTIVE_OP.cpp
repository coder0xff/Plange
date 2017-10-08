// This file was generated using Parlex's cpp_generator

#include "CONSTRUCTIVE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "COMPOSITION.hpp"
#include "COMPOUND.hpp"
#include "NULL_COALESCE.hpp"
#include "PREPEND.hpp"
#include "CONSTRUCTIVE_OP.hpp"

namespace plc {

CONSTRUCTIVE_OP CONSTRUCTIVE_OP::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return CONSTRUCTIVE_OP(parlex::details::document::element<CONSTRUCTIVE_OP_base>::build(b, n));
}

} // namespace plc
