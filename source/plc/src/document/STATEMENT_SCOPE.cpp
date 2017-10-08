// This file was generated using Parlex's cpp_generator

#include "STATEMENT_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "STATEMENT.hpp"
#include "STATEMENT_SCOPE.hpp"

namespace plc {

STATEMENT_SCOPE STATEMENT_SCOPE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return STATEMENT_SCOPE(parlex::details::document::element<STATEMENT_SCOPE_base>::build(b, n));
}

} // namespace plc
