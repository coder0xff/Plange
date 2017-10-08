// This file was generated using Parlex's cpp_generator

#include "ASM_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_STATEMENT.hpp"
#include "IC.hpp"
#include "ASM_SCOPE.hpp"

namespace plc {

ASM_SCOPE ASM_SCOPE::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return ASM_SCOPE(parlex::details::document::element<ASM_SCOPE_base>::build(b, n));
}

} // namespace plc
