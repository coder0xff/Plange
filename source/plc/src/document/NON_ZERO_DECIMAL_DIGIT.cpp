// This file was generated using Parlex's cpp_generator

#include "NON_ZERO_DECIMAL_DIGIT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_ZERO_DECIMAL_DIGIT.hpp"

namespace plc {

NON_ZERO_DECIMAL_DIGIT NON_ZERO_DECIMAL_DIGIT::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_ZERO_DECIMAL_DIGIT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_ZERO_DECIMAL_DIGIT(parlex::details::document::element<NON_ZERO_DECIMAL_DIGIT_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::NON_ZERO_DECIMAL_DIGIT::recognizer() {
	return plange_grammar::get().NON_ZERO_DECIMAL_DIGIT.get_recognizer();
}
