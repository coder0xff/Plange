// This file was generated using Parlex's cpp_generator

#include "STATIC.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "STATIC.hpp"

namespace plc {

STATIC STATIC::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().STATIC.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATIC(parlex::detail::document::element<STATIC_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::STATIC::recognizer() {
	return plange_grammar::get().STATIC.get_recognizer();
}
