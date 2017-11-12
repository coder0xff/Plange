// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SYMMETRIC_DIFFERENCE_HPP
#define INCLUDED_SYMMETRIC_DIFFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SYMMETRIC_DIFFERENCE {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::details::document::text<literal_0xE20x8A0x96_t> dontCare2;
	
	std::vector<erased<IC>> field_3;
	
	erased<EXPRESSION> field_4;
	


	explicit SYMMETRIC_DIFFERENCE(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::details::document::text<literal_0xE20x8A0x96_t> && dontCare2, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	SYMMETRIC_DIFFERENCE(SYMMETRIC_DIFFERENCE const & other) = default;
	SYMMETRIC_DIFFERENCE(SYMMETRIC_DIFFERENCE && move) = default;

	static SYMMETRIC_DIFFERENCE build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_SYMMETRIC_DIFFERENCE_HPP
