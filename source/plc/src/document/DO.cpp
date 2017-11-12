// This file was generated using Parlex's cpp_generator

#include "DO.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "PARENTHETICAL.hpp"

plc::DO::field_2_t_1_t plc::DO::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_while_t>,
		parlex::details::document::text<literal_until_t>
	>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<PARENTHETICAL>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::DO plc::DO::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DO.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_do_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[3], w);
	return DO(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::details::recognizer const & plc::DO::recognizer() {
	return plange_grammar::get().DO.get_recognizer();
}
