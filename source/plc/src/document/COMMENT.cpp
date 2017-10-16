// This file was generated using Parlex's cpp_generator

#include "COMMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::COMMENT plc::COMMENT::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().COMMENT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; ///* 
	auto v_0 = parlex::details::document::element<std::vector<parlex::details::document::built_in_terminal<parlex::details::all_t>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //*/ 
	return COMMENT(std::move(v_0));
}

