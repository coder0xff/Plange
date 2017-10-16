// This file was generated using Parlex's cpp_generator

#include "MAP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::MAP::field_1_t_1_t::field_6_t_1_t plc::MAP::field_1_t_1_t::field_6_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //, 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[4], w);
	assert(w.pos != w.end); ++w.pos; //: 
	auto v_4 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[6], w);
	auto v_5 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[7], w);
	return field_6_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}

plc::MAP::field_1_t_1_t plc::MAP::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	assert(w.pos != w.end); ++w.pos; //: 
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[5], w);
	auto v_5 = parlex::details::document::element<std::vector<field_6_t_1_t>>::build(document, *children[6], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}

plc::MAP plc::MAP::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().MAP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //{ 
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	assert(w.pos != w.end); ++w.pos; //} 
	return MAP(std::move(v_0), std::move(v_1));
}

