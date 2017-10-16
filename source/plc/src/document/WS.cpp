// This file was generated using Parlex's cpp_generator

#include "WS.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::WS plc::WS::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().WS.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::built_in_terminal<parlex::details::white_space_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<parlex::details::document::built_in_terminal<parlex::details::white_space_t>>>::build(document, *children[1], w);
	return WS(std::move(v_0), std::move(v_1));
}

