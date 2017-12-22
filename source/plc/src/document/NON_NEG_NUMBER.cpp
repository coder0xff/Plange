// This file was generated using Parlex's cpp_generator

#include "NON_NEG_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "NON_NEG_FRACTIONAL.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

#include "NON_NEG_NUMBER.hpp"

namespace plc {

NON_NEG_NUMBER NON_NEG_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_NEG_NUMBER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_NUMBER(parlex::detail::document::element<NON_NEG_NUMBER_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::NON_NEG_NUMBER::recognizer() {
	return plange_grammar::get().NON_NEG_NUMBER.get_recognizer();
}
