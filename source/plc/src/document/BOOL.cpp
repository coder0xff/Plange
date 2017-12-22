// This file was generated using Parlex's cpp_generator

#include "BOOL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "BOOL.hpp"

namespace plc {

BOOL BOOL::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().BOOL.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BOOL(parlex::detail::document::element<BOOL_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::BOOL::recognizer() {
	return plange_grammar::get().BOOL.get_recognizer();
}
