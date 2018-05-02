// This file was generated using Parlex's cpp_generator

#include "EXTERN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXTERN.hpp"

namespace plc {

EXTERN EXTERN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EXTERN(parlex::detail::document::element<EXTERN_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::EXTERN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXTERN));
	return result;
}
