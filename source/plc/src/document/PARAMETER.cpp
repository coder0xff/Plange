// This file was generated using Parlex's cpp_generator

#include "PARAMETER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "PARAMETER_ANALYTIC.hpp"
#include "PARAMETER_NATURAL.hpp"

#include "PARAMETER.hpp"

namespace plc {

PARAMETER PARAMETER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().PARAMETER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER(parlex::detail::document::element<PARAMETER_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::PARAMETER::recognizer() {
	return plange_grammar::get().PARAMETER.get_recognizer();
}
