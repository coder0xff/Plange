// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_ANALYSIS_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "UNIT_DIVISION.hpp"
#include "UNIT_EXPONENTIATION.hpp"
#include "UNIT_MULTIPLICATION.hpp"

#include "DIMENSIONAL_ANALYSIS_OP.hpp"

namespace plc {

DIMENSIONAL_ANALYSIS_OP DIMENSIONAL_ANALYSIS_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DIMENSIONAL_ANALYSIS_OP.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSIONAL_ANALYSIS_OP(parlex::detail::document::element<DIMENSIONAL_ANALYSIS_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::DIMENSIONAL_ANALYSIS_OP::recognizer() {
	return plange_grammar::get().DIMENSIONAL_ANALYSIS_OP.get_recognizer();
}
