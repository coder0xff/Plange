// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_PLATFORM.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "FUNCTION_MODIFIER_4.hpp"
#include "ICR.hpp"
#include "PLATFORM.hpp"

plc::FUNCTION_MODIFIER_PLATFORM::field_2_t_1_t plc::FUNCTION_MODIFIER_PLATFORM::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ICR>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<PLATFORM>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_PLATFORM::field_3_t_1_t plc::FUNCTION_MODIFIER_PLATFORM::field_3_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ICR>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<FUNCTION_MODIFIER_4>>::build(document, *children[1], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION_MODIFIER_PLATFORM plc::FUNCTION_MODIFIER_PLATFORM::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FUNCTION_MODIFIER_PLATFORM.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<PLATFORM>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_2_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(document, *children[2], w);
	return FUNCTION_MODIFIER_PLATFORM(std::move(v_0), std::move(v_1), std::move(v_2));
}

