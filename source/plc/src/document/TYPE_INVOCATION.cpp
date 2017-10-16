// This file was generated using Parlex's cpp_generator

#include "TYPE_INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ARGUMENT.hpp"
#include "ARGUMENT_PACK.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::TYPE_INVOCATION::field_2_t::head_t_1_t plc::TYPE_INVOCATION::field_2_t::head_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>
	>>::build(document, *children[1], w);
	return head_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_INVOCATION::field_2_t::field_1_t_1_t::field_2_t_1_t plc::TYPE_INVOCATION::field_2_t::field_1_t_1_t::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>
	>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_INVOCATION::field_2_t::field_1_t_1_t plc::TYPE_INVOCATION::field_2_t::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //, 
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_INVOCATION::field_2_t plc::TYPE_INVOCATION::field_2_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //< 
	auto v_0 = parlex::details::document::element<std::optional<head_t_1_t>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::vector<field_1_t_1_t>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //> 
	return field_2_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::TYPE_INVOCATION plc::TYPE_INVOCATION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().TYPE_INVOCATION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<field_2_t>::build(document, *children[1], w);
	return TYPE_INVOCATION(std::move(v_0), std::move(v_1));
}

