// This file was generated using Parlex's cpp_generator

#include "TIME.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::TIME::field_08_t_1_t plc::TIME::field_08_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //. 
	auto v_0 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::vector<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>>::build(document, *children[2], w);
	return field_08_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TIME::field_09_t_1_t_2_t::field_4_t_1_t plc::TIME::field_09_t_1_t_2_t::field_4_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //: 
	auto v_0 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[2], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TIME::field_09_t_1_t_2_t plc::TIME::field_09_t_1_t_2_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		literal_0x2B_t,
		literal_0x2D_t
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(document, *children[3], w);
	return field_09_t_1_t_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::TIME plc::TIME::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().TIME.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<bool>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[2], w);
	assert(w.pos != w.end); ++w.pos; //: 
	auto v_3 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[5], w);
	assert(w.pos != w.end); ++w.pos; //: 
	auto v_5 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[7], w);
	auto v_6 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t>>::build(document, *children[8], w);
	auto v_7 = parlex::details::document::element<std::optional<field_08_t_1_t>>::build(document, *children[9], w);
	auto v_8 = parlex::details::document::element<std::optional<std::variant<
		literal_Z_t,
		field_09_t_1_t_2_t
	>>>::build(document, *children[10], w);
	return TIME(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8));
}

