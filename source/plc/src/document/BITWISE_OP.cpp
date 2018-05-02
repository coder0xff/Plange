// This file was generated using Parlex's cpp_generator

#include "BITWISE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "BIT_AND.hpp"
#include "BIT_OR.hpp"
#include "BIT_XOR.hpp"

#include "BITWISE_OP.hpp"

namespace plc {

BITWISE_OP BITWISE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BITWISE_OP(parlex::detail::document::element<BITWISE_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::BITWISE_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BITWISE_OP));
	return result;
}
