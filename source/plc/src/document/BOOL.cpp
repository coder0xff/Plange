// This file was generated using Parlex's cpp_generator

#include "BOOL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "BOOL.hpp"

namespace plc {

BOOL BOOL::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BOOL(parlex::detail::document::element<BOOL_base>::build(b, w));
}

} // namespace plc

parlex::detail::state_machine const & plc::BOOL::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BOOL));
	return result;
}
