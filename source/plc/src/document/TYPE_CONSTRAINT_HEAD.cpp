// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_HEAD.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ATTRIBUTE.hpp"
#include "IC.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "VOLATILE_IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "VOLATILE_TYPE_DEREFERENCE.hpp"
#include "XML_DOC_STRING.hpp"

plc::TYPE_CONSTRAINT_HEAD::field_1_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<XML_DOC_STRING>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_CONSTRAINT_HEAD::field_2_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ATTRIBUTE>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_CONSTRAINT_HEAD::field_3_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_3_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<VISIBILITY_MODIFIER>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_CONSTRAINT_HEAD::field_4_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_4_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //static 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_4_t_1_t(std::move(v_0));
}

plc::TYPE_CONSTRAINT_HEAD::field_5_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_5_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //extern 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_5_t_1_t(std::move(v_0));
}

plc::TYPE_CONSTRAINT_HEAD plc::TYPE_CONSTRAINT_HEAD::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().TYPE_CONSTRAINT_HEAD.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_2_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(document, *children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(document, *children[3], w);
	auto v_4 = parlex::details::document::element<std::optional<field_5_t_1_t>>::build(document, *children[4], w);
	auto v_5 = parlex::details::document::element<std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<VOLATILE_TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>,
		erased<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	>>::build(document, *children[5], w);
	return TYPE_CONSTRAINT_HEAD(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}

