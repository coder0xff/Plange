// This file was generated using Parlex's cpp_generator

#include "PARAMETER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "PARAMETER_ANALYTIC.hpp"
#include "PARAMETER_NATURAL.hpp"

#include "PARAMETER.hpp"

namespace plc {

PARAMETER PARAMETER::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().PARAMETER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER(parlex::details::document::element<PARAMETER_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::PARAMETER::recognizer() {
	return plange_grammar::get().PARAMETER.get_recognizer();
}
