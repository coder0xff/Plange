// This file was generated using Parlex's cpp_generator

#include "OBJECT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "INHERITANCE_LIST.hpp"
#include "TYPE_SCOPE.hpp"

plc::OBJECT::field_2_t_1_t plc::OBJECT::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //inheriting 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<INHERITANCE_LIST>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::OBJECT::field_3_t_1_t plc::OBJECT::field_3_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //implementing 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<INHERITANCE_LIST>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::OBJECT plc::OBJECT::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().OBJECT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //object 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //{ 
	auto v_3 = parlex::details::document::element<erased<TYPE_SCOPE>>::build(document, *children[5], w);
	assert(w.pos != w.end); ++w.pos; //} 
	return OBJECT(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

