// This file was generated using Parlex's cpp_generator

#include "SYMMETRIC_DIFFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::SYMMETRIC_DIFFERENCE plc::SYMMETRIC_DIFFERENCE::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().SYMMETRIC_DIFFERENCE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //⊖ 
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[4], w);
	return SYMMETRIC_DIFFERENCE(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

