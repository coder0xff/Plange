// This file was generated using Parlex's cpp_generator

#include "THIS_FUNC.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::THIS_FUNC::field_1_t_1_t plc::THIS_FUNC::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}

plc::THIS_FUNC plc::THIS_FUNC::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().THIS_FUNC.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_this_func_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	return THIS_FUNC(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::THIS_FUNC::recognizer() {
	return plange_grammar::get().THIS_FUNC.get_recognizer();
}
