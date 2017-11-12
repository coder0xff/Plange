// This file was generated using Parlex's cpp_generator

#include "BITWISE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BIT_AND.hpp"
#include "BIT_OR.hpp"
#include "BIT_XOR.hpp"

#include "BITWISE_OP.hpp"

namespace plc {

BITWISE_OP BITWISE_OP::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().BITWISE_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BITWISE_OP(parlex::details::document::element<BITWISE_OP_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::BITWISE_OP::recognizer() {
	return plange_grammar::get().BITWISE_OP.get_recognizer();
}
