// This file was generated using Parlex's cpp_generator

#include "MAP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::MAP::field_1_t_1_t::field_6_t_1_t plc::MAP::field_1_t_1_t::field_6_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[5], w);
	auto v_6 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[6], w);
	auto v_7 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[7], w);
	return field_6_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7));
}

plc::MAP::field_1_t_1_t plc::MAP::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[5], w);
	auto v_6 = parlex::detail::document::element<std::vector<field_6_t_1_t>>::build(&*children[6], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}

plc::MAP plc::MAP::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().MAP.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[3], w);
	return MAP(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::detail::recognizer const & plc::MAP::recognizer() {
	return plange_grammar::get().MAP.get_recognizer();
}
