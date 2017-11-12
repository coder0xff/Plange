// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_ANALYSIS_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "UNIT_DIVISION.hpp"
#include "UNIT_EXPONENTIATION.hpp"
#include "UNIT_MULTIPLICATION.hpp"

#include "DIMENSIONAL_ANALYSIS_OP.hpp"

namespace plc {

DIMENSIONAL_ANALYSIS_OP DIMENSIONAL_ANALYSIS_OP::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DIMENSIONAL_ANALYSIS_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSIONAL_ANALYSIS_OP(parlex::details::document::element<DIMENSIONAL_ANALYSIS_OP_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::DIMENSIONAL_ANALYSIS_OP::recognizer() {
	return plange_grammar::get().DIMENSIONAL_ANALYSIS_OP.get_recognizer();
}
