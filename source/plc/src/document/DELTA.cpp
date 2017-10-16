// This file was generated using Parlex's cpp_generator

#include "DELTA.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "WHOLE_NUMBER.hpp"

plc::DELTA::field_2_t_1_t plc::DELTA::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //^ 
	auto v_0 = parlex::details::document::element<erased<WHOLE_NUMBER>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0));
}

plc::DELTA plc::DELTA::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().DELTA.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		literal_0xCE0x94_t,
		literal__delta__t
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[2], w);
	return DELTA(std::move(v_0), std::move(v_1), std::move(v_2));
}

