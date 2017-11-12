// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIVISION_HPP
#define INCLUDED_DIVISION_HPP

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

struct DIVISION {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		parlex::details::document::text<literal_0xC30xB7_t>,
		parlex::details::document::text<literal_0x2F_t>
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit DIVISION(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			parlex::details::document::text<literal_0xC30xB7_t>,
			parlex::details::document::text<literal_0x2F_t>
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	DIVISION(DIVISION const & other) = default;
	DIVISION(DIVISION && move) = default;

	static DIVISION build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_DIVISION_HPP
