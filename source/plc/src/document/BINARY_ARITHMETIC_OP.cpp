// This file was generated using Parlex's cpp_generator

#include "BINARY_ARITHMETIC_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ADDITION.hpp"
#include "ADD_SUB.hpp"
#include "DIVISION.hpp"
#include "EXPONENTIATION.hpp"
#include "INTEGER_DIVISION.hpp"
#include "MODULATION.hpp"
#include "MULTIPLICATIVE_OP.hpp"
#include "SHIFTL.hpp"
#include "SHIFTR.hpp"
#include "SUBTRACTION.hpp"

#include "BINARY_ARITHMETIC_OP.hpp"

namespace plc {

BINARY_ARITHMETIC_OP BINARY_ARITHMETIC_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_ARITHMETIC_OP(parlex::detail::document::element<BINARY_ARITHMETIC_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::BINARY_ARITHMETIC_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_ARITHMETIC_OP));
	return result;
}
