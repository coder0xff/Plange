// This file was generated using Parlex's cpp_generator

#include "NEAREST_INTEGER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

#include "NEAREST_INTEGER.hpp"

namespace plc {

NEAREST_INTEGER NEAREST_INTEGER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NEAREST_INTEGER(parlex::detail::document::element<NEAREST_INTEGER_base>::build(b, w));
}

} // namespace plc
plc::NEAREST_INTEGER_1_t plc::NEAREST_INTEGER_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x89_t>>::build(&*children[4], w);
	return NEAREST_INTEGER_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4));
}

plc::NEAREST_INTEGER_2_t plc::NEAREST_INTEGER_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C__t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x270x7C_t>>::build(&*children[4], w);
	return NEAREST_INTEGER_2_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4));
}


parlex::detail::acceptor const & plc::NEAREST_INTEGER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NEAREST_INTEGER));
	return result;
}
