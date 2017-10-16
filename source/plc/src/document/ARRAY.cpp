// This file was generated using Parlex's cpp_generator

#include "ARRAY.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::ARRAY::field_2_t_1_t::field_1_t_1_t plc::ARRAY::field_2_t_1_t::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //, 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[3], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ARRAY::field_2_t_1_t plc::ARRAY::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_1_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ARRAY plc::ARRAY::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().ARRAY.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //[ 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	assert(w.pos != w.end); ++w.pos; //] 
	return ARRAY(std::move(v_0), std::move(v_1));
}

