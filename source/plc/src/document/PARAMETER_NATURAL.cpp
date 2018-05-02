// This file was generated using Parlex's cpp_generator

#include "PARAMETER_NATURAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"

#include "PARAMETER_NATURAL.hpp"

namespace plc {

PARAMETER_NATURAL PARAMETER_NATURAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER_NATURAL(parlex::detail::document::element<PARAMETER_NATURAL_base>::build(b, w));
}

} // namespace plc
plc::PARAMETER_NATURAL_1_t::field_1_t_1_t plc::PARAMETER_NATURAL_1_t::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<TYPE_DEREFERENCE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::PARAMETER_NATURAL_1_t plc::PARAMETER_NATURAL_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>>::build(&*children[2], w);
	return PARAMETER_NATURAL_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::PARAMETER_NATURAL_2_t::field_1_t_1_t plc::PARAMETER_NATURAL_2_t::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::PARAMETER_NATURAL_2_t plc::PARAMETER_NATURAL_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3D_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>>::build(&*children[7], w);
	return PARAMETER_NATURAL_2_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7));
}


parlex::detail::acceptor const & plc::PARAMETER_NATURAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARAMETER_NATURAL));
	return result;
}
