// This file was generated using Parlex's cpp_generator

#include "FUNCTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BLOCK.hpp"
#include "FUNCTION_MODIFIER_0.hpp"
#include "IC.hpp"
#include "PARAMETER.hpp"

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //, 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<PARAMETER>>::build(document, *children[3], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<PARAMETER>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_1_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FUNCTION::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //( 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	assert(w.pos != w.end); ++w.pos; //) 
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[4], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FUNCTION::field_2_t_1_t plc::FUNCTION::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<FUNCTION_MODIFIER_0>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION plc::FUNCTION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FUNCTION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<erased<BLOCK>>::build(document, *children[2], w);
	return FUNCTION(std::move(v_0), std::move(v_1), std::move(v_2));
}

