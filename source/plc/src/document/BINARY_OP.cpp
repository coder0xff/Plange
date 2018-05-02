// This file was generated using Parlex's cpp_generator

#include "BINARY_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "BINARY_ARITHMETIC_OP.hpp"
#include "BINARY_COLLECTION_OP.hpp"
#include "BINARY_LOGICAL_OP.hpp"
#include "BITWISE_OP.hpp"
#include "CONSTRUCTIVE_OP.hpp"
#include "RELATIONAL_OP.hpp"

#include "BINARY_OP.hpp"

namespace plc {

BINARY_OP BINARY_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_OP(parlex::detail::document::element<BINARY_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::BINARY_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_OP));
	return result;
}
