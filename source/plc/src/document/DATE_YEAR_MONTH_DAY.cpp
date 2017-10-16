// This file was generated using Parlex's cpp_generator

#include "DATE_YEAR_MONTH_DAY.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::DATE_YEAR_MONTH_DAY plc::DATE_YEAR_MONTH_DAY::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().DATE_YEAR_MONTH_DAY.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[2], w);
	auto v_3 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //- 
	auto v_4 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[5], w);
	auto v_5 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[6], w);
	assert(w.pos != w.end); ++w.pos; //- 
	auto v_6 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[8], w);
	auto v_7 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[9], w);
	return DATE_YEAR_MONTH_DAY(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7));
}

