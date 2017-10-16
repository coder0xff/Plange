// This file was generated using Parlex's cpp_generator

#include "FOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASSIGNMENT_CHAIN.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "STATEMENT_SCOPE.hpp"

plc::FOR::initializer_t_1_t plc::FOR::initializer_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<STATEMENT_SCOPE>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return initializer_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FOR::step_t_1_t::field_2_t_1_t plc::FOR::step_t_1_t::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //, 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<ASSIGNMENT_CHAIN>>::build(document, *children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FOR::step_t_1_t plc::FOR::step_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ASSIGNMENT_CHAIN>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_2_t_1_t>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	return step_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FOR plc::FOR::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //for 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //( 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	auto v_2 = parlex::details::document::element<std::optional<initializer_t_1_t>>::build(document, *children[4], w);
	auto v_3 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[5], w);
	auto v_4 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[6], w);
	assert(w.pos != w.end); ++w.pos; //; 
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[8], w);
	auto v_6 = parlex::details::document::element<std::optional<step_t_1_t>>::build(document, *children[9], w);
	assert(w.pos != w.end); ++w.pos; //) 
	auto v_7 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[11], w);
	auto v_8 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[12], w);
	return FOR(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8));
}

