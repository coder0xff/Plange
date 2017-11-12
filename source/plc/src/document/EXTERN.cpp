// This file was generated using Parlex's cpp_generator

#include "EXTERN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXTERN.hpp"

namespace plc {

EXTERN EXTERN::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().EXTERN.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EXTERN(parlex::details::document::element<EXTERN_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::EXTERN::recognizer() {
	return plange_grammar::get().EXTERN.get_recognizer();
}
