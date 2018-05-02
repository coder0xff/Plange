// This file was generated using Parlex's cpp_generator

#include "IF.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "PARENTHETICAL.hpp"

plc::IF::field_3_t_1_t plc::IF::field_3_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_elif_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<PARENTHETICAL>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[5], w);
	return field_3_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5));
}

plc::IF::field_4_t_1_t plc::IF::field_4_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_else_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	return field_4_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::IF plc::IF::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_if_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<field_3_t_1_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::optional<field_4_t_1_t>>::build(&*children[6], w);
	return IF(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6));
}


parlex::detail::acceptor const & plc::IF::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IF));
	return result;
}
