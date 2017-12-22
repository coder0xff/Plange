// This file was generated using Parlex's cpp_generator

#include "SET.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::SET::elements_t_1_t::field_2_t_1_t plc::SET::elements_t_1_t::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::SET::elements_t_1_t plc::SET::elements_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	return elements_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::SET plc::SET::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().SET.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B0x7C_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<elements_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x7D_t>>::build(&*children[3], w);
	return SET(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::detail::recognizer const & plc::SET::recognizer() {
	return plange_grammar::get().SET.get_recognizer();
}
