// This file was generated using Parlex's cpp_generator

#include "DATE_YEAR_MONTH_DAY.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::DATE_YEAR_MONTH_DAY plc::DATE_YEAR_MONTH_DAY::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DATE_YEAR_MONTH_DAY.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[5], w);
	auto v_6 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[6], w);
	auto v_7 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[7], w);
	auto v_8 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[8], w);
	auto v_9 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[9], w);
	return DATE_YEAR_MONTH_DAY(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8), std::move(v_9));
}


parlex::detail::recognizer const & plc::DATE_YEAR_MONTH_DAY::recognizer() {
	return plange_grammar::get().DATE_YEAR_MONTH_DAY.get_recognizer();
}
