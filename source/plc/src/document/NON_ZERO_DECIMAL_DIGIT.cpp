// This file was generated using Parlex's cpp_generator

#include "NON_ZERO_DECIMAL_DIGIT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "NON_ZERO_DECIMAL_DIGIT.hpp"

namespace plc {

NON_ZERO_DECIMAL_DIGIT NON_ZERO_DECIMAL_DIGIT::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_ZERO_DECIMAL_DIGIT.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_ZERO_DECIMAL_DIGIT(parlex::detail::document::element<NON_ZERO_DECIMAL_DIGIT_base>::build(b, w));
}

} // namespace plc

parlex::detail::recognizer const & plc::NON_ZERO_DECIMAL_DIGIT::recognizer() {
	return plange_grammar::get().NON_ZERO_DECIMAL_DIGIT.get_recognizer();
}
