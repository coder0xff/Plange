// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_STABILITY.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "FUNCTION_MODIFIER_1.hpp"
#include "ICR.hpp"

plc::FUNCTION_MODIFIER_STABILITY::field_1_t_1_t plc::FUNCTION_MODIFIER_STABILITY::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<ICR>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<FUNCTION_MODIFIER_1>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_STABILITY plc::FUNCTION_MODIFIER_STABILITY::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FUNCTION_MODIFIER_STABILITY.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_stable_t>,
		parlex::detail::document::text<literal_unstable_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	return FUNCTION_MODIFIER_STABILITY(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::FUNCTION_MODIFIER_STABILITY::recognizer() {
	return plange_grammar::get().FUNCTION_MODIFIER_STABILITY.get_recognizer();
}
