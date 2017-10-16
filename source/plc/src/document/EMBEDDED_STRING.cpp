// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EMBEDDED_STRING_INTERIOR.hpp"

plc::EMBEDDED_STRING plc::EMBEDDED_STRING::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().EMBEDDED_STRING.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //""" 
	auto v_0 = parlex::details::document::element<erased<EMBEDDED_STRING_INTERIOR>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //""" 
	return EMBEDDED_STRING(std::move(v_0));
}

