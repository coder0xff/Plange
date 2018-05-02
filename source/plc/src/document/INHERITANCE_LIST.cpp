// This file was generated using Parlex's cpp_generator

#include "INHERITANCE_LIST.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "INHERITANCE_ITEM_PREFIX.hpp"

plc::INHERITANCE_LIST::field_2_t_1_t plc::INHERITANCE_LIST::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<erased<INHERITANCE_ITEM_PREFIX>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4));
}

plc::INHERITANCE_LIST plc::INHERITANCE_LIST::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<erased<INHERITANCE_ITEM_PREFIX>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[2], w);
	return INHERITANCE_LIST(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::INHERITANCE_LIST::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INHERITANCE_LIST));
	return result;
}
