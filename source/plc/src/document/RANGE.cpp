// This file was generated using Parlex's cpp_generator

#include "RANGE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "RANGE.hpp"

namespace plc {

RANGE RANGE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RANGE(parlex::detail::document::element<RANGE_base>::build(b, w));
}

} // namespace plc
plc::RANGE_1_t plc::RANGE_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	>>::build(&*children[6], w);
	return RANGE_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6));
}

plc::RANGE_2_t plc::RANGE_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x5B_t>,
		parlex::detail::document::text<literal_0x28_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[6], w);
	return RANGE_2_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6));
}

plc::RANGE_3_t plc::RANGE_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x28_t>,
		parlex::detail::document::text<literal_0x5B_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	>>::build(&*children[8], w);
	return RANGE_3_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7), std::move(v8));
}


parlex::detail::acceptor const & plc::RANGE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RANGE));
	return result;
}
