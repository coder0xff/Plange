// This file was generated using Parlex's cpp_generator

#include "WHOLE_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::WHOLE_NUMBER plc::WHOLE_NUMBER::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().WHOLE_NUMBER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_1_t>,
		parlex::details::document::text<literal_2_t>,
		parlex::details::document::text<literal_3_t>,
		parlex::details::document::text<literal_4_t>,
		parlex::details::document::text<literal_5_t>,
		parlex::details::document::text<literal_6_t>,
		parlex::details::document::text<literal_7_t>,
		parlex::details::document::text<literal_8_t>,
		parlex::details::document::text<literal_9_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<std::variant<
		parlex::details::document::text<literal_0_t>,
		parlex::details::document::text<literal_1_t>,
		parlex::details::document::text<literal_2_t>,
		parlex::details::document::text<literal_3_t>,
		parlex::details::document::text<literal_4_t>,
		parlex::details::document::text<literal_5_t>,
		parlex::details::document::text<literal_6_t>,
		parlex::details::document::text<literal_7_t>,
		parlex::details::document::text<literal_8_t>,
		parlex::details::document::text<literal_9_t>
	>>>::build(&*children[1], w);
	return WHOLE_NUMBER(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::WHOLE_NUMBER::recognizer() {
	return plange_grammar::get().WHOLE_NUMBER.get_recognizer();
}
