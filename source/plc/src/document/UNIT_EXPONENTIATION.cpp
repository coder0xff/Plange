// This file was generated using Parlex's cpp_generator

#include "UNIT_EXPONENTIATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSION.hpp"
#include "NON_FRACTIONAL.hpp"

plc::UNIT_EXPONENTIATION plc::UNIT_EXPONENTIATION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().UNIT_EXPONENTIATION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<DIMENSION>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //^ 
	auto v_1 = parlex::details::document::element<erased<NON_FRACTIONAL>>::build(document, *children[2], w);
	return UNIT_EXPONENTIATION(std::move(v_0), std::move(v_1));
}

