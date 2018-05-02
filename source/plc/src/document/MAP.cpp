// This file was generated using Parlex's cpp_generator

#include "MAP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::MAP::field_1_t_1_t::field_6_t_1_t plc::MAP::field_1_t_1_t::field_6_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[7], w);
	return field_6_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7));
}

plc::MAP::field_1_t_1_t plc::MAP::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::vector<field_6_t_1_t>>::build(&*children[6], w);
	return field_1_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6));
}

plc::MAP plc::MAP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[3], w);
	return MAP(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}


parlex::detail::acceptor const & plc::MAP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MAP));
	return result;
}
