// This file was generated using Parlex's cpp_generator

#include "PARAMETER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "PARAMETER_ANALYTIC.hpp"
#include "PARAMETER_NATURAL.hpp"
#include "PARAMETER.hpp"

namespace plc {

PARAMETER PARAMETER::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return PARAMETER(parlex::details::document::element<PARAMETER_base>::build(b, n));
}

} // namespace plc
