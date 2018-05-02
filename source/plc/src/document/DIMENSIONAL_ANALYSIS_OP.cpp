// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_ANALYSIS_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "UNIT_DIVISION.hpp"
#include "UNIT_EXPONENTIATION.hpp"
#include "UNIT_MULTIPLICATION.hpp"

#include "DIMENSIONAL_ANALYSIS_OP.hpp"

namespace plc {

DIMENSIONAL_ANALYSIS_OP DIMENSIONAL_ANALYSIS_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSIONAL_ANALYSIS_OP(parlex::detail::document::element<DIMENSIONAL_ANALYSIS_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::DIMENSIONAL_ANALYSIS_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIMENSIONAL_ANALYSIS_OP));
	return result;
}
