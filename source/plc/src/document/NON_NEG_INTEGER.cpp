// This file was generated using Parlex's cpp_generator

#include "NON_NEG_INTEGER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_ZERO_DECIMAL_DIGIT.hpp"

#include "NON_NEG_INTEGER.hpp"

namespace plc {

NON_NEG_INTEGER NON_NEG_INTEGER::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_NEG_INTEGER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_INTEGER(parlex::details::document::element<NON_NEG_INTEGER_base>::build(b, w));
}

} // namespace plc
plc::NON_NEG_INTEGER_1_t plc::NON_NEG_INTEGER_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<NON_ZERO_DECIMAL_DIGIT>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>>>::build(&*children[1], w);
	return NON_NEG_INTEGER_1_t(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::NON_NEG_INTEGER::recognizer() {
	return plange_grammar::get().NON_NEG_INTEGER.get_recognizer();
}
