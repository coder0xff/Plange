// This file was generated using Parlex's cpp_generator

#include "DIMENSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSIONAL_ANALYSIS_OP.hpp"
#include "IDENTIFIER.hpp"
#include "DIMENSION.hpp"

namespace plc {

DIMENSION DIMENSION::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return DIMENSION(parlex::details::document::element<DIMENSION_base>::build(b, n));
}

} // namespace plc
