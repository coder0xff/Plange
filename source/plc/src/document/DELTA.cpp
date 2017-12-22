// This file was generated using Parlex's cpp_generator

#include "DELTA.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "WHOLE_NUMBER.hpp"

plc::DELTA::field_2_t_1_t plc::DELTA::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<WHOLE_NUMBER>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::DELTA plc::DELTA::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DELTA.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xCE0x94_t>,
		parlex::detail::document::text<literal__delta__t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	return DELTA(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::DELTA::recognizer() {
	return plange_grammar::get().DELTA.get_recognizer();
}
