// This file was generated using Parlex's cpp_generator

#include "DIMENSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DIMENSIONAL_ANALYSIS_OP.hpp"
#include "IDENTIFIER.hpp"

#include "DIMENSION.hpp"

namespace plc {

DIMENSION DIMENSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSION(parlex::detail::document::element<DIMENSION_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::DIMENSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIMENSION));
	return result;
}
