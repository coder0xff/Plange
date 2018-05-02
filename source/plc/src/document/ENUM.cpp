// This file was generated using Parlex's cpp_generator

#include "ENUM.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ENUM_ELEMENT.hpp"
#include "IC.hpp"
#include "INHERITANCE_LIST.hpp"

plc::ENUM::field_2_t_1_t plc::ENUM::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::ENUM::field_3_t_1_t plc::ENUM::field_3_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_3_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::ENUM::field_4_t_1_t::field_1_t_1_t plc::ENUM::field_4_t_1_t::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<ENUM_ELEMENT>>::build(&*children[3], w);
	return field_1_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::ENUM::field_4_t_1_t plc::ENUM::field_4_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<ENUM_ELEMENT>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_1_t_1_t>>::build(&*children[1], w);
	return field_4_t_1_t(std::move(v0), std::move(v1));
}

plc::ENUM plc::ENUM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_enum_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_3_t_1_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::optional<field_4_t_1_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return ENUM(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6));
}


parlex::detail::acceptor const & plc::ENUM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ENUM));
	return result;
}
