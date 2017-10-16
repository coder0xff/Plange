// This file was generated using Parlex's cpp_generator

#include "BLOCK.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "STATEMENT_SCOPE.hpp"

plc::BLOCK plc::BLOCK::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().BLOCK.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //{ 
	auto v_0 = parlex::details::document::element<erased<STATEMENT_SCOPE>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //} 
	return BLOCK(std::move(v_0));
}

