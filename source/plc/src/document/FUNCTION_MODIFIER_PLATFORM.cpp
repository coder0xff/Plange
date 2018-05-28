// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_PLATFORM.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "FUNCTION_MODIFIER_4.hpp"
#include "IC.hpp"
#include "PLATFORM.hpp"

plc::FUNCTION_MODIFIER_PLATFORM::field_2_t_1_t plc::FUNCTION_MODIFIER_PLATFORM::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<PLATFORM>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::FUNCTION_MODIFIER_PLATFORM::field_3_t_1_t plc::FUNCTION_MODIFIER_PLATFORM::field_3_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<FUNCTION_MODIFIER_4>>::build(&*children[2], w);
	return field_3_t_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::FUNCTION_MODIFIER_PLATFORM plc::FUNCTION_MODIFIER_PLATFORM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<PLATFORM>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_3_t_1_t>>::build(&*children[2], w);
	return FUNCTION_MODIFIER_PLATFORM(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_PLATFORM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_PLATFORM));
	return result;
}
