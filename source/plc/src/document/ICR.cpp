// This file was generated using Parlex's cpp_generator

#include "ICR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"

plc::ICR plc::ICR::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().ICR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<IC>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return ICR(std::move(v_0), std::move(v_1));
}

