// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSION.hpp"
#include "NON_NEG_NUMBER.hpp"

plc::DIMENSIONAL_NUMBER plc::DIMENSIONAL_NUMBER::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().DIMENSIONAL_NUMBER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<NON_NEG_NUMBER>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<DIMENSION>>::build(document, *children[1], w);
	return DIMENSIONAL_NUMBER(std::move(v_0), std::move(v_1));
}

