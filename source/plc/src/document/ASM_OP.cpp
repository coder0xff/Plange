// This file was generated using Parlex's cpp_generator

#include "ASM_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::ASM_OP plc::ASM_OP::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().ASM_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::lowercase_letter_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<parlex::details::document::built_in_terminal<parlex::details::lowercase_letter_t>>>::build(document, *children[1], w);
	return ASM_OP(std::move(v_0), std::move(v_1));
}

