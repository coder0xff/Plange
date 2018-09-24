// This file was generated using Parlex's cpp_generator

#include "IDENTIFIER_SPECIFICATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ATTRIBUTE.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "XML_DOC_STRING.hpp"

plc::IDENTIFIER_SPECIFICATION::attributes_t plc::IDENTIFIER_SPECIFICATION::attributes_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ATTRIBUTE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return attributes_t(std::move(v0), std::move(v1));
}

plc::IDENTIFIER_SPECIFICATION::visibility_t plc::IDENTIFIER_SPECIFICATION::visibility_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return visibility_t(std::move(v0), std::move(v1));
}

plc::IDENTIFIER_SPECIFICATION::static__t plc::IDENTIFIER_SPECIFICATION::static__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_static_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return static__t(std::move(v0), std::move(v1));
}

plc::IDENTIFIER_SPECIFICATION::extern__t plc::IDENTIFIER_SPECIFICATION::extern__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_extern_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return extern__t(std::move(v0), std::move(v1));
}

plc::IDENTIFIER_SPECIFICATION plc::IDENTIFIER_SPECIFICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<XML_DOC_STRING>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<attributes_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<visibility_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<static__t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<extern__t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[5], w);
	return IDENTIFIER_SPECIFICATION(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5));
}


parlex::detail::acceptor const & plc::IDENTIFIER_SPECIFICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IDENTIFIER_SPECIFICATION));
	return result;
}
