// This file was generated using Parlex's cpp_generator

#include "STATIC.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "STATIC.hpp"

namespace plc {

STATIC STATIC::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().STATIC.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATIC(parlex::details::document::element<STATIC_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::STATIC::recognizer() {
	return plange_grammar::get().STATIC.get_recognizer();
}
