// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_ATOMIC.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_3.hpp"
#include "ICR.hpp"

plc::FUNCTION_MODIFIER_ATOMIC::field_1_t_1_t plc::FUNCTION_MODIFIER_ATOMIC::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ICR>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<FUNCTION_MODIFIER_3>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_ATOMIC plc::FUNCTION_MODIFIER_ATOMIC::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FUNCTION_MODIFIER_ATOMIC.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //atomic 
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[1], w);
	return FUNCTION_MODIFIER_ATOMIC(std::move(v_0));
}

