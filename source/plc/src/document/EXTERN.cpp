// This file was generated using Parlex's cpp_generator

#include "EXTERN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXTERN.hpp"

namespace plc {

EXTERN EXTERN::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().EXTERN.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EXTERN(parlex::detail::document::element<EXTERN_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::EXTERN::recognizer() {
	return plange_grammar::get().EXTERN.get_recognizer();
}
