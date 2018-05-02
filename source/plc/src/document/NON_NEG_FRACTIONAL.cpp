// This file was generated using Parlex's cpp_generator

#include "NON_NEG_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "NON_NEG_FRACTIONAL.hpp"

namespace plc {

NON_NEG_FRACTIONAL NON_NEG_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_FRACTIONAL(parlex::detail::document::element<NON_NEG_FRACTIONAL_base>::build(b, w));
}

} // namespace plc
plc::NON_NEG_FRACTIONAL_1_t plc::NON_NEG_FRACTIONAL_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[3], w);
	return NON_NEG_FRACTIONAL_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::NON_NEG_FRACTIONAL_2_t plc::NON_NEG_FRACTIONAL_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[2], w);
	return NON_NEG_FRACTIONAL_2_t(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::NON_NEG_FRACTIONAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_NEG_FRACTIONAL));
	return result;
}
