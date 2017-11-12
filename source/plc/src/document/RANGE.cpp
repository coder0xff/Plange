// This file was generated using Parlex's cpp_generator

#include "RANGE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "RANGE.hpp"

namespace plc {

RANGE RANGE::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().RANGE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RANGE(parlex::details::document::element<RANGE_base>::build(b, w));
}

} // namespace plc
plc::RANGE_1_t plc::RANGE_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x5D_t>,
		parlex::details::document::text<literal_0x29_t>
	>>::build(&*children[6], w);
	return RANGE_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}

plc::RANGE_2_t plc::RANGE_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x5B_t>,
		parlex::details::document::text<literal_0x28_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<parlex::details::document::text<literal_0x29_t>>::build(&*children[6], w);
	return RANGE_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}

plc::RANGE_3_t plc::RANGE_3_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x28_t>,
		parlex::details::document::text<literal_0x5B_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[6], w);
	auto v_7 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[7], w);
	auto v_8 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x5D_t>,
		parlex::details::document::text<literal_0x29_t>
	>>::build(&*children[8], w);
	return RANGE_3_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8));
}


parlex::details::recognizer const & plc::RANGE::recognizer() {
	return plange_grammar::get().RANGE.get_recognizer();
}
