// This file was generated using Parlex's cpp_generator

#include "REGEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "STRING.hpp"

plc::REGEX plc::REGEX::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().REGEX.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //R 
	auto v_0 = parlex::details::document::element<erased<STRING>>::build(document, *children[1], w);
	return REGEX(std::move(v_0));
}

