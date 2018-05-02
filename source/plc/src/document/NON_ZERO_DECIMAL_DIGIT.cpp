// This file was generated using Parlex's cpp_generator

#include "NON_ZERO_DECIMAL_DIGIT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "NON_ZERO_DECIMAL_DIGIT.hpp"

namespace plc {

NON_ZERO_DECIMAL_DIGIT NON_ZERO_DECIMAL_DIGIT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_ZERO_DECIMAL_DIGIT(parlex::detail::document::element<NON_ZERO_DECIMAL_DIGIT_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::NON_ZERO_DECIMAL_DIGIT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_ZERO_DECIMAL_DIGIT));
	return result;
}
