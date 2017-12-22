// This file was generated using Parlex's cpp_generator

#include "ARGUMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"

#include "ARGUMENT.hpp"

namespace plc {

ARGUMENT ARGUMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ARGUMENT.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ARGUMENT(parlex::detail::document::element<ARGUMENT_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::ARGUMENT::recognizer() {
	return plange_grammar::get().ARGUMENT.get_recognizer();
}
