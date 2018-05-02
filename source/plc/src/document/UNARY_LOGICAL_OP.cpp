// This file was generated using Parlex's cpp_generator

#include "UNARY_LOGICAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ALL.hpp"
#include "EXISTS.hpp"
#include "EXISTS_ONE.hpp"
#include "NOT.hpp"

#include "UNARY_LOGICAL_OP.hpp"

namespace plc {

UNARY_LOGICAL_OP UNARY_LOGICAL_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_LOGICAL_OP(parlex::detail::document::element<UNARY_LOGICAL_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::UNARY_LOGICAL_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNARY_LOGICAL_OP));
	return result;
}
