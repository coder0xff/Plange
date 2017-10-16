// This file was generated using Parlex's cpp_generator

#include "DIMENSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSIONAL_ANALYSIS_OP.hpp"
#include "IDENTIFIER.hpp"

#include "DIMENSION.hpp"

namespace plc {

DIMENSION DIMENSION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().DIMENSION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSION(parlex::details::document::element<DIMENSION_base>::build(document, b, w));
}

} // namespace plc
