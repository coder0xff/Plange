// This file was generated using Parlex's cpp_generator

#include "MEMBER_OFFSET.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "WHOLE_NUMBER.hpp"

plc::MEMBER_OFFSET plc::MEMBER_OFFSET::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x40_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<WHOLE_NUMBER>>::build(&*children[2], w);
	return MEMBER_OFFSET(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::MEMBER_OFFSET::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MEMBER_OFFSET));
	return result;
}
