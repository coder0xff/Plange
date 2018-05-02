// This file was generated using Parlex's cpp_generator

#include "UNARY_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ALLOCATION.hpp"
#include "CARDINALITY.hpp"
#include "KLEENE_STAR.hpp"
#include "UNARY_ARITHMETIC_OP.hpp"
#include "UNARY_LOGICAL_OP.hpp"

#include "UNARY_OP.hpp"

namespace plc {

UNARY_OP UNARY_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_OP(parlex::detail::document::element<UNARY_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::UNARY_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNARY_OP));
	return result;
}
