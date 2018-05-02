// This file was generated using Parlex's cpp_generator

#include "MULTIPLICATIVE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "CROSS_PRODUCT.hpp"
#include "DOT_PRODUCT.hpp"
#include "MULTIPLICATION.hpp"

#include "MULTIPLICATIVE_OP.hpp"

namespace plc {

MULTIPLICATIVE_OP MULTIPLICATIVE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return MULTIPLICATIVE_OP(parlex::detail::document::element<MULTIPLICATIVE_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::MULTIPLICATIVE_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MULTIPLICATIVE_OP));
	return result;
}
