// This file was generated using Parlex's cpp_generator

#include "RELATIONAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "CASTS.hpp"
#include "DOWNCASTS.hpp"
#include "EXACTLY.hpp"
#include "IMPLEMENTS.hpp"
#include "INEQUALITY.hpp"
#include "INHERITS.hpp"
#include "IS.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"
#include "UPCASTS.hpp"

#include "RELATIONAL_OP.hpp"

namespace plc {

RELATIONAL_OP RELATIONAL_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RELATIONAL_OP(parlex::detail::document::element<RELATIONAL_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::RELATIONAL_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RELATIONAL_OP));
	return result;
}
