// This file was generated using Parlex's cpp_generator

#include "ARGUMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "ARGUMENT.hpp"

namespace plc {

ARGUMENT ARGUMENT::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return ARGUMENT(parlex::details::document::element<ARGUMENT_base>::build(b, n));
}

} // namespace plc
