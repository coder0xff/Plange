// This file was generated using Parlex's cpp_generator

#include "IMPLICIT_TYPE_DEREFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"

plc::IMPLICIT_TYPE_DEREFERENCE plc::IMPLICIT_TYPE_DEREFERENCE::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().IMPLICIT_TYPE_DEREFERENCE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //< 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //> 
	return IMPLICIT_TYPE_DEREFERENCE(std::move(v_0));
}

