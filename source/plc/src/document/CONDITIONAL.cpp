// This file was generated using Parlex's cpp_generator

#include "CONDITIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::CONDITIONAL plc::CONDITIONAL::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().CONDITIONAL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //? 
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[5], w);
	assert(w.pos != w.end); ++w.pos; //: 
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[7], w);
	auto v_6 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[8], w);
	return CONDITIONAL(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}

