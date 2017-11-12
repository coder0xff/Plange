// This file was generated using Parlex's cpp_generator

#include "VISIBILITY_MODIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "VISIBILITY_MODIFIER.hpp"

namespace plc {

VISIBILITY_MODIFIER VISIBILITY_MODIFIER::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().VISIBILITY_MODIFIER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return VISIBILITY_MODIFIER(parlex::details::document::element<VISIBILITY_MODIFIER_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::VISIBILITY_MODIFIER::recognizer() {
	return plange_grammar::get().VISIBILITY_MODIFIER.get_recognizer();
}
