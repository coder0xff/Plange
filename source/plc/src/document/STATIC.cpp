// This file was generated using Parlex's cpp_generator

#include "STATIC.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "STATIC.hpp"

namespace plc {

STATIC STATIC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATIC(parlex::detail::document::element<STATIC_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::STATIC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STATIC));
	return result;
}
