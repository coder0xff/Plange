// This file was generated using Parlex's cpp_generator

#include "ARGUMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"

#include "ARGUMENT.hpp"

namespace plc {

ARGUMENT ARGUMENT::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ARGUMENT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ARGUMENT(parlex::details::document::element<ARGUMENT_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::ARGUMENT::recognizer() {
	return plange_grammar::get().ARGUMENT.get_recognizer();
}
