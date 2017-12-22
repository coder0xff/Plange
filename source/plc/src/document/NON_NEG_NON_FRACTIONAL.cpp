// This file was generated using Parlex's cpp_generator

#include "NON_NEG_NON_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "HEX.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "OCTAL.hpp"

#include "NON_NEG_NON_FRACTIONAL.hpp"

namespace plc {

NON_NEG_NON_FRACTIONAL NON_NEG_NON_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_NEG_NON_FRACTIONAL.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_NON_FRACTIONAL(parlex::detail::document::element<NON_NEG_NON_FRACTIONAL_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::NON_NEG_NON_FRACTIONAL::recognizer() {
	return plange_grammar::get().NON_NEG_NON_FRACTIONAL.get_recognizer();
}
