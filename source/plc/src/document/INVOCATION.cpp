// This file was generated using Parlex's cpp_generator

#include "INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ARRAY_INVOCATION.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "TYPE_INVOCATION.hpp"
#include "INVOCATION.hpp"

namespace plc {

INVOCATION INVOCATION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return INVOCATION(parlex::details::document::element<INVOCATION_base>::build(b, n));
}

} // namespace plc
