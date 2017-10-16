// This file was generated using Parlex's cpp_generator

#include "HEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::HEX plc::HEX::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().HEX.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //0x 
	auto v_0 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::hexadecimal_digit_t>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::vector<parlex::details::document::built_in_terminal<parlex::details::hexadecimal_digit_t>>>::build(document, *children[2], w);
	return HEX(std::move(v_0), std::move(v_1));
}

