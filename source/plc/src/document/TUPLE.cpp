// This file was generated using Parlex's cpp_generator

#include "TUPLE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::TUPLE::field_3_t_1_t plc::TUPLE::field_3_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	return field_3_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::TUPLE plc::TUPLE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x280x7C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<field_3_t_1_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x29_t>>::build(&*children[5], w);
	return TUPLE(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5));
}


parlex::detail::acceptor const & plc::TUPLE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TUPLE));
	return result;
}
