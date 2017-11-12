// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_2.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_3.hpp"
#include "FUNCTION_MODIFIER_ATOMIC.hpp"

#include "FUNCTION_MODIFIER_2.hpp"

namespace plc {

FUNCTION_MODIFIER_2 FUNCTION_MODIFIER_2::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FUNCTION_MODIFIER_2.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_2(parlex::details::document::element<FUNCTION_MODIFIER_2_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::FUNCTION_MODIFIER_2::recognizer() {
	return plange_grammar::get().FUNCTION_MODIFIER_2.get_recognizer();
}
