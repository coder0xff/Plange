// This file was generated using Parlex's cpp_generator

#include "BREAK.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "ICR.hpp"
#include "IDENTIFIER.hpp"

plc::BREAK::field_1_t_1_t_1_t plc::BREAK::field_1_t_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //[ 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[4], w);
	assert(w.pos != w.end); ++w.pos; //] 
	return field_1_t_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::BREAK::field_1_t_1_t_2_t plc::BREAK::field_1_t_1_t_2_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<ICR>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(document, *children[1], w);
	return field_1_t_1_t_2_t(std::move(v_0), std::move(v_1));
}

plc::BREAK plc::BREAK::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().BREAK.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //break 
	auto v_0 = parlex::details::document::element<std::optional<std::variant<
		field_1_t_1_t_1_t,
		field_1_t_1_t_2_t
	>>>::build(document, *children[1], w);
	return BREAK(std::move(v_0));
}

