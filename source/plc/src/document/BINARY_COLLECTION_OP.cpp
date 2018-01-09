// This file was generated using Parlex's cpp_generator

#include "BINARY_COLLECTION_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "BIJECTION.hpp"
#include "INTERSECTION.hpp"
#include "SYMMETRIC_DIFFERENCE.hpp"
#include "UNION.hpp"

#include "BINARY_COLLECTION_OP.hpp"

namespace plc {

BINARY_COLLECTION_OP BINARY_COLLECTION_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_COLLECTION_OP(parlex::detail::document::element<BINARY_COLLECTION_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::BINARY_COLLECTION_OP::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_COLLECTION_OP));
	return result;
}
