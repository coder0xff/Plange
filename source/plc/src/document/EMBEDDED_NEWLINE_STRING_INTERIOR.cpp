// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_NEWLINE_STRING_INTERIOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EMBEDDED_NEWLINE_STRING_INTERIOR.hpp"
#include "PAYLOAD.hpp"

#include "EMBEDDED_NEWLINE_STRING_INTERIOR.hpp"

namespace plc {

EMBEDDED_NEWLINE_STRING_INTERIOR EMBEDDED_NEWLINE_STRING_INTERIOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EMBEDDED_NEWLINE_STRING_INTERIOR(parlex::detail::document::element<EMBEDDED_NEWLINE_STRING_INTERIOR_base>::build(b, w));
}

} // namespace plc
plc::EMBEDDED_NEWLINE_STRING_INTERIOR_1_t plc::EMBEDDED_NEWLINE_STRING_INTERIOR_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<PAYLOAD>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[2], w);
	return EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::EMBEDDED_NEWLINE_STRING_INTERIOR_2_t plc::EMBEDDED_NEWLINE_STRING_INTERIOR_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x22_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<EMBEDDED_NEWLINE_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x22_t>>::build(&*children[2], w);
	return EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::EMBEDDED_NEWLINE_STRING_INTERIOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_NEWLINE_STRING_INTERIOR));
	return result;
}
