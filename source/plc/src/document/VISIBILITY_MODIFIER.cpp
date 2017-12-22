// This file was generated using Parlex's cpp_generator

#include "VISIBILITY_MODIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "VISIBILITY_MODIFIER.hpp"

namespace plc {

VISIBILITY_MODIFIER VISIBILITY_MODIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().VISIBILITY_MODIFIER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return VISIBILITY_MODIFIER(parlex::detail::document::element<VISIBILITY_MODIFIER_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::VISIBILITY_MODIFIER::recognizer() {
	return plange_grammar::get().VISIBILITY_MODIFIER.get_recognizer();
}
