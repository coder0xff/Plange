// This file was generated using Parlex's cpp_generator

#include "NON_NEG_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_NEG_FRACTIONAL.hpp"

namespace plc {

NON_NEG_FRACTIONAL NON_NEG_FRACTIONAL::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_NEG_FRACTIONAL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_FRACTIONAL(parlex::details::document::element<NON_NEG_FRACTIONAL_base>::build(b, w));
}

} // namespace plc
plc::NON_NEG_FRACTIONAL_1_t plc::NON_NEG_FRACTIONAL_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_0x2E_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>>>::build(&*children[3], w);
	return NON_NEG_FRACTIONAL_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::NON_NEG_FRACTIONAL_2_t plc::NON_NEG_FRACTIONAL_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x2E_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>>>::build(&*children[2], w);
	return NON_NEG_FRACTIONAL_2_t(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::NON_NEG_FRACTIONAL::recognizer() {
	return plange_grammar::get().NON_NEG_FRACTIONAL.get_recognizer();
}
