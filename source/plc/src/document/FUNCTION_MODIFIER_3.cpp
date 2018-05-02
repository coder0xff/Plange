// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_3.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "FUNCTION_MODIFIER_4.hpp"
#include "FUNCTION_MODIFIER_PLATFORM.hpp"

#include "FUNCTION_MODIFIER_3.hpp"

namespace plc {

FUNCTION_MODIFIER_3 FUNCTION_MODIFIER_3::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_3(parlex::detail::document::element<FUNCTION_MODIFIER_3_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_3::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_3));
	return result;
}
