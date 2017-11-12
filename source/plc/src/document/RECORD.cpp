// This file was generated using Parlex's cpp_generator

#include "RECORD.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ICR.hpp"
#include "TYPE.hpp"

plc::RECORD plc::RECORD::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().RECORD.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_record_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<ICR>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<TYPE>>::build(&*children[2], w);
	return RECORD(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::RECORD::recognizer() {
	return plange_grammar::get().RECORD.get_recognizer();
}
