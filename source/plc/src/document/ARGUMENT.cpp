// This file was generated using Parlex's cpp_generator

#include "ARGUMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"

#include "ARGUMENT.hpp"

namespace plc {

ARGUMENT ARGUMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ARGUMENT(parlex::detail::document::element<ARGUMENT_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::ARGUMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARGUMENT));
	return result;
}
