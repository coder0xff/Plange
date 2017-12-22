// This file was generated using Parlex's cpp_generator

#include "NEAREST_INTEGER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "NEAREST_INTEGER.hpp"

namespace plc {

NEAREST_INTEGER NEAREST_INTEGER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NEAREST_INTEGER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NEAREST_INTEGER(parlex::detail::document::element<NEAREST_INTEGER_base>::build(b, w));
}

} // namespace plc
plc::NEAREST_INTEGER_1_t plc::NEAREST_INTEGER_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8A_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x89_t>>::build(&*children[4], w);
	return NEAREST_INTEGER_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::NEAREST_INTEGER_2_t plc::NEAREST_INTEGER_2_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C__t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x270x7C_t>>::build(&*children[4], w);
	return NEAREST_INTEGER_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::detail::recognizer const & plc::NEAREST_INTEGER::recognizer() {
	return plange_grammar::get().NEAREST_INTEGER.get_recognizer();
}
