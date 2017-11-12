// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_MODEL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_CALLING_CONVENTION.hpp"
#include "ICR.hpp"

plc::FUNCTION_MODIFIER_MODEL::field_1_t_1_t plc::FUNCTION_MODIFIER_MODEL::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ICR>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<FUNCTION_MODIFIER_CALLING_CONVENTION>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_MODEL plc::FUNCTION_MODIFIER_MODEL::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FUNCTION_MODIFIER_MODEL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_pure_t>,
		parlex::details::document::text<literal_imperative_t>,
		parlex::details::document::text<literal_opaque_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	return FUNCTION_MODIFIER_MODEL(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::FUNCTION_MODIFIER_MODEL::recognizer() {
	return plange_grammar::get().FUNCTION_MODIFIER_MODEL.get_recognizer();
}
