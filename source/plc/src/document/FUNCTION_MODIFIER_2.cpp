// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_2.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "FUNCTION_MODIFIER_3.hpp"
#include "FUNCTION_MODIFIER_ATOMIC.hpp"

#include "FUNCTION_MODIFIER_2.hpp"

namespace plc {

FUNCTION_MODIFIER_2 FUNCTION_MODIFIER_2::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FUNCTION_MODIFIER_2.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_2(parlex::detail::document::element<FUNCTION_MODIFIER_2_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::FUNCTION_MODIFIER_2::recognizer() {
	return plange_grammar::get().FUNCTION_MODIFIER_2.get_recognizer();
}
