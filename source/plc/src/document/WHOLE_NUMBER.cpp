// This file was generated using Parlex's cpp_generator

#include "WHOLE_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::WHOLE_NUMBER plc::WHOLE_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_1_t>,
		parlex::detail::document::text<literal_2_t>,
		parlex::detail::document::text<literal_3_t>,
		parlex::detail::document::text<literal_4_t>,
		parlex::detail::document::text<literal_5_t>,
		parlex::detail::document::text<literal_6_t>,
		parlex::detail::document::text<literal_7_t>,
		parlex::detail::document::text<literal_8_t>,
		parlex::detail::document::text<literal_9_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<literal_0_t>,
		parlex::detail::document::text<literal_1_t>,
		parlex::detail::document::text<literal_2_t>,
		parlex::detail::document::text<literal_3_t>,
		parlex::detail::document::text<literal_4_t>,
		parlex::detail::document::text<literal_5_t>,
		parlex::detail::document::text<literal_6_t>,
		parlex::detail::document::text<literal_7_t>,
		parlex::detail::document::text<literal_8_t>,
		parlex::detail::document::text<literal_9_t>
	>>>::build(&*children[1], w);
	return WHOLE_NUMBER(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::WHOLE_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().WHOLE_NUMBER));
	return result;
}
