// This file was generated using Parlex's cpp_generator

#include "PLATFORM.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::PLATFORM plc::PLATFORM::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().PLATFORM.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //_ 
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::built_in_terminal<parlex::details::letter_t>,
		parlex::details::document::built_in_terminal<parlex::details::number_t>
	>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::vector<std::variant<
		parlex::details::document::built_in_terminal<parlex::details::letter_t>,
		parlex::details::document::built_in_terminal<parlex::details::number_t>,
		literal___t
	>>>::build(document, *children[2], w);
	return PLATFORM(std::move(v_0), std::move(v_1));
}

