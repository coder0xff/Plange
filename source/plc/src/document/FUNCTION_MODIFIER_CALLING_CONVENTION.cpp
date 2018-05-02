// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_CALLING_CONVENTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "FUNCTION_MODIFIER_CALLING_CONVENTION.hpp"

namespace plc {

FUNCTION_MODIFIER_CALLING_CONVENTION FUNCTION_MODIFIER_CALLING_CONVENTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_CALLING_CONVENTION(parlex::detail::document::element<FUNCTION_MODIFIER_CALLING_CONVENTION_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_CALLING_CONVENTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_CALLING_CONVENTION));
	return result;
}
