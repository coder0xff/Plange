// This file was generated using Parlex's cpp_generator

#include "CEILING.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "CEILING.hpp"

namespace plc {

CEILING CEILING::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().CEILING.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return CEILING(parlex::details::document::element<CEILING_base>::build(b, w));
}

} // namespace plc
plc::CEILING_1_t plc::CEILING_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0xE20x8C0x88_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0xE20x8C0x89_t>>::build(&*children[4], w);
	return CEILING_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::CEILING_2_t plc::CEILING_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x7C0x27_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0x270x7C_t>>::build(&*children[4], w);
	return CEILING_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::details::recognizer const & plc::CEILING::recognizer() {
	return plange_grammar::get().CEILING.get_recognizer();
}
