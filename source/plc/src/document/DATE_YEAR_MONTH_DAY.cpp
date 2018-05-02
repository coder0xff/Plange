// This file was generated using Parlex's cpp_generator

#include "DATE_YEAR_MONTH_DAY.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::DATE_YEAR_MONTH_DAY plc::DATE_YEAR_MONTH_DAY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[9], w);
	return DATE_YEAR_MONTH_DAY(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7), std::move(v8), std::move(v9));
}


parlex::detail::acceptor const & plc::DATE_YEAR_MONTH_DAY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE_YEAR_MONTH_DAY));
	return result;
}
