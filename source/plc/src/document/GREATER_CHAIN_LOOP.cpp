// This file was generated using Parlex's cpp_generator

#include "GREATER_CHAIN_LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "GREATER_CHAIN_LOOP.hpp"
#include "IC.hpp"

plc::GREATER_CHAIN_LOOP::field_3_t_1_t plc::GREATER_CHAIN_LOOP::field_3_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<GREATER_CHAIN_LOOP>>::build(document, *children[1], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1));
}

plc::GREATER_CHAIN_LOOP plc::GREATER_CHAIN_LOOP::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().GREATER_CHAIN_LOOP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		literal_0x3D_t,
		literal_0x3E_t,
		literal_0x3D0x3E_t,
		literal_0xE20x890xA5_t
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(document, *children[3], w);
	return GREATER_CHAIN_LOOP(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

