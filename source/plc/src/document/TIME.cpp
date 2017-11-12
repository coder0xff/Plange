// This file was generated using Parlex's cpp_generator

#include "TIME.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::TIME::field_08_t_1_t plc::TIME::field_08_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x2E_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>>>::build(&*children[2], w);
	return field_08_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::TIME::field_09_t_1_t_2_t::field_4_t_1_t plc::TIME::field_09_t_1_t_2_t::field_4_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x3A_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[2], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::TIME::field_09_t_1_t_2_t plc::TIME::field_09_t_1_t_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x2B_t>,
		parlex::details::document::text<literal_0x2D_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(&*children[3], w);
	return field_09_t_1_t_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::TIME plc::TIME::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TIME.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<parlex::details::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<parlex::details::document::text<literal_0x3A_t>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<parlex::details::document::text<literal_0x3A_t>>::build(&*children[6], w);
	auto v_7 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[7], w);
	auto v_8 = parlex::details::document::element<parlex::details::document::text<parlex::details::decimal_digit_t>>::build(&*children[8], w);
	auto v_9 = parlex::details::document::element<std::optional<field_08_t_1_t>>::build(&*children[9], w);
	auto v_10 = parlex::details::document::element<std::optional<std::variant<
		parlex::details::document::text<literal_Z_t>,
		field_09_t_1_t_2_t
	>>>::build(&*children[10], w);
	return TIME(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8), std::move(v_9), std::move(v_10));
}


parlex::details::recognizer const & plc::TIME::recognizer() {
	return plange_grammar::get().TIME.get_recognizer();
}
