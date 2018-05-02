// This file was generated using Parlex's cpp_generator

#include "PARAMETER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "PARAMETER_ANALYTIC.hpp"
#include "PARAMETER_NATURAL.hpp"

#include "PARAMETER.hpp"

namespace plc {

PARAMETER PARAMETER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER(parlex::detail::document::element<PARAMETER_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::PARAMETER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARAMETER));
	return result;
}
