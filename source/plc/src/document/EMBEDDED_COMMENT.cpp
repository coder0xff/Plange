// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_COMMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EMBEDDED_COMMENT_INTERIOR.hpp"

plc::EMBEDDED_COMMENT plc::EMBEDDED_COMMENT::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().EMBEDDED_COMMENT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; ///*** 
	auto v_0 = parlex::details::document::element<erased<EMBEDDED_COMMENT_INTERIOR>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //***/ 
	return EMBEDDED_COMMENT(std::move(v_0));
}

