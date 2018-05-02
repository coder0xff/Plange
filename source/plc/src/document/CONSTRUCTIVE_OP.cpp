// This file was generated using Parlex's cpp_generator

#include "CONSTRUCTIVE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "COMPOSITION.hpp"
#include "COMPOUND.hpp"
#include "NULL_COALESCE.hpp"
#include "PREPEND.hpp"

#include "CONSTRUCTIVE_OP.hpp"

namespace plc {

CONSTRUCTIVE_OP CONSTRUCTIVE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return CONSTRUCTIVE_OP(parlex::detail::document::element<CONSTRUCTIVE_OP_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::CONSTRUCTIVE_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CONSTRUCTIVE_OP));
	return result;
}
