// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONDITIONAL_HPP
#define INCLUDED_CONDITIONAL_HPP

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

struct CONDITIONAL {
	erased<EXPRESSION> condition;
	
	std::vector<erased<IC>> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> true_case;
	
	std::vector<erased<IC>> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> false_case;
	


	explicit CONDITIONAL(
		erased<EXPRESSION> && condition, std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && true_case, std::vector<erased<IC>> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && false_case) : condition(std::move(condition)), field_1(std::move(field_1)), field_2(std::move(field_2)), true_case(std::move(true_case)), field_3(std::move(field_3)), field_4(std::move(field_4)), false_case(std::move(false_case)) {}

	CONDITIONAL(CONDITIONAL const & other) = default;
	CONDITIONAL(CONDITIONAL && move) = default;

	static CONDITIONAL build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CONDITIONAL_HPP
