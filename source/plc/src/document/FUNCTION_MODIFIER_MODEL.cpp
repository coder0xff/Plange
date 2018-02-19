// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_MODEL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "FUNCTION_MODIFIER_CALLING_CONVENTION.hpp"
#include "ICR.hpp"

plc::FUNCTION_MODIFIER_MODEL::field_1_t_1_t plc::FUNCTION_MODIFIER_MODEL::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<ICR>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<FUNCTION_MODIFIER_CALLING_CONVENTION>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::FUNCTION_MODIFIER_MODEL plc::FUNCTION_MODIFIER_MODEL::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_pure_t>,
		parlex::detail::document::text<literal_imperative_t>,
		parlex::detail::document::text<literal_opaque_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	return FUNCTION_MODIFIER_MODEL(std::move(v0), std::move(v1));
}


parlex::detail::state_machine const & plc::FUNCTION_MODIFIER_MODEL::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_MODEL));
	return result;
}
