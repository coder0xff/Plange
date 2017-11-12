// This file was generated using Parlex's cpp_generator

#include "FLOOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "FLOOR.hpp"

namespace plc {

FLOOR FLOOR::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FLOOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FLOOR(parlex::details::document::element<FLOOR_base>::build(b, w));
}

} // namespace plc
plc::FLOOR_1_t plc::FLOOR_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0xE20x8C0x8A_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0xE20x8C0x8B_t>>::build(&*children[4], w);
	return FLOOR_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::FLOOR_2_t plc::FLOOR_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x7C__t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal__0x7C_t>>::build(&*children[4], w);
	return FLOOR_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::details::recognizer const & plc::FLOOR::recognizer() {
	return plange_grammar::get().FLOOR.get_recognizer();
}
