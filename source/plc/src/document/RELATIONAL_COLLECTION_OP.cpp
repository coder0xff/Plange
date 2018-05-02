// This file was generated using Parlex's cpp_generator

#include "RELATIONAL_COLLECTION_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "HAS.hpp"
#include "IN.hpp"
#include "NOT_HAS.hpp"
#include "NOT_IN.hpp"

#include "RELATIONAL_COLLECTION_OP.hpp"

namespace plc {

RELATIONAL_COLLECTION_OP RELATIONAL_COLLECTION_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RELATIONAL_COLLECTION_OP(parlex::detail::document::element<RELATIONAL_COLLECTION_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::RELATIONAL_COLLECTION_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RELATIONAL_COLLECTION_OP));
	return result;
}
