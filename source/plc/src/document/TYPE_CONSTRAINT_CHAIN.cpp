// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASSIGNMENT_CHAIN.hpp"
#include "DECLARATION.hpp"
#include "DEFINITION.hpp"
#include "IC.hpp"
#include "TYPE_CONSTRAINT_CHAIN.hpp"

plc::TYPE_CONSTRAINT_CHAIN::field_2_t_1_t plc::TYPE_CONSTRAINT_CHAIN::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //, 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<TYPE_CONSTRAINT_CHAIN>>::build(document, *children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::TYPE_CONSTRAINT_CHAIN plc::TYPE_CONSTRAINT_CHAIN::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().TYPE_CONSTRAINT_CHAIN.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		erased<DECLARATION>,
		erased<ASSIGNMENT_CHAIN>,
		erased<DEFINITION>
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[1], w);
	return TYPE_CONSTRAINT_CHAIN(std::move(v_0), std::move(v_1));
}

