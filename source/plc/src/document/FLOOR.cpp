// This file was generated using Parlex's cpp_generator

#include "FLOOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "FLOOR.hpp"

namespace plc {

FLOOR FLOOR::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FLOOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FLOOR(parlex::details::document::element<FLOOR_base>::build(document, b, w));
}

} // namespace plc
plc::FLOOR_1_t plc::FLOOR_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //⌊ 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //⌋ 
	return FLOOR_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FLOOR_2_t plc::FLOOR_2_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //|_ 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //_| 
	return FLOOR_2_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

