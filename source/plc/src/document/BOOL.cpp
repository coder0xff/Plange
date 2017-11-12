// This file was generated using Parlex's cpp_generator

#include "BOOL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BOOL.hpp"

namespace plc {

BOOL BOOL::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().BOOL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BOOL(parlex::details::document::element<BOOL_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::BOOL::recognizer() {
	return plange_grammar::get().BOOL.get_recognizer();
}
