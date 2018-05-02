// This file was generated using Parlex's cpp_generator

#include "VISIBILITY_MODIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "VISIBILITY_MODIFIER.hpp"

namespace plc {

VISIBILITY_MODIFIER VISIBILITY_MODIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return VISIBILITY_MODIFIER(parlex::detail::document::element<VISIBILITY_MODIFIER_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::VISIBILITY_MODIFIER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().VISIBILITY_MODIFIER));
	return result;
}
