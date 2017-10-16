// This file was generated using Parlex's cpp_generator

#include "IF.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "PARENTHETICAL.hpp"

plc::IF::field_3_t_1_t plc::IF::field_3_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //elif 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<PARENTHETICAL>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[5], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::IF::field_4_t_1_t plc::IF::field_4_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //else 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[3], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::IF plc::IF::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().IF.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //if 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<PARENTHETICAL>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<std::vector<field_3_t_1_t>>::build(document, *children[5], w);
	auto v_5 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(document, *children[6], w);
	return IF(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}

