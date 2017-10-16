// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_THROWING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ARRAY.hpp"
#include "FUNCTION_MODIFIER_2.hpp"
#include "IC.hpp"
#include "ICR.hpp"

plc::FUNCTION_MODIFIER_THROWING::field_1_t_1_t plc::FUNCTION_MODIFIER_THROWING::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<ARRAY>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_THROWING::field_2_t_1_t plc::FUNCTION_MODIFIER_THROWING::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ICR>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<FUNCTION_MODIFIER_2>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_THROWING plc::FUNCTION_MODIFIER_THROWING::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FUNCTION_MODIFIER_THROWING.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //throwing 
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	return FUNCTION_MODIFIER_THROWING(std::move(v_0), std::move(v_1));
}

