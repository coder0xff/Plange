// This file was generated using Parlex's cpp_generator

#include "TRY.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::TRY::field_6_t_1_t plc::TRY::field_6_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //catch 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[2], w);
	return field_6_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TRY::field_7_t_1_t plc::TRY::field_7_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //finally 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[3], w);
	return field_7_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::TRY plc::TRY::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().TRY.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //try 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //catch 
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[5], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[6], w);
	auto v_5 = parlex::details::document::element<std::vector<field_6_t_1_t>>::build(document, *children[7], w);
	auto v_6 = parlex::details::document::element<std::optional<field_7_t_1_t>>::build(document, *children[8], w);
	return TRY(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}

