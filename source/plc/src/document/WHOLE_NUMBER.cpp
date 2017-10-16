// This file was generated using Parlex's cpp_generator

#include "WHOLE_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::WHOLE_NUMBER plc::WHOLE_NUMBER::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().WHOLE_NUMBER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		literal_1_t,
		literal_2_t,
		literal_3_t,
		literal_4_t,
		literal_5_t,
		literal_6_t,
		literal_7_t,
		literal_8_t,
		literal_9_t
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<std::variant<
		literal_0_t,
		literal_1_t,
		literal_2_t,
		literal_3_t,
		literal_4_t,
		literal_5_t,
		literal_6_t,
		literal_7_t,
		literal_8_t,
		literal_9_t
	>>>::build(document, *children[1], w);
	return WHOLE_NUMBER(std::move(v_0), std::move(v_1));
}

