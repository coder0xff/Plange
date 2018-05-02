// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONDITIONAL_HPP
#define INCLUDED_CONDITIONAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct CONDITIONAL {
	erased<EXPRESSION> condition;
	
	std::vector<erased<IC>> field_01;
	
	parlex::detail::document::text<literal_0x3F_t> dontCare2;
	
	std::vector<erased<IC>> field_02;
	
	erased<EXPRESSION> true_case;
	
	std::vector<erased<IC>> field_03;
	
	parlex::detail::document::text<literal_0x3A_t> dontCare6;
	
	std::vector<erased<IC>> field_04;
	
	erased<EXPRESSION> false_case;
	


	explicit CONDITIONAL(
		erased<EXPRESSION> && condition, std::vector<erased<IC>> && field_01, parlex::detail::document::text<literal_0x3F_t> && dontCare2, std::vector<erased<IC>> && field_02, erased<EXPRESSION> && true_case, std::vector<erased<IC>> && field_03, parlex::detail::document::text<literal_0x3A_t> && dontCare6, std::vector<erased<IC>> && field_04, erased<EXPRESSION> && false_case) : condition(std::move(condition)), field_01(std::move(field_01)), dontCare2(std::move(dontCare2)), field_02(std::move(field_02)), true_case(std::move(true_case)), field_03(std::move(field_03)), dontCare6(std::move(dontCare6)), field_04(std::move(field_04)), false_case(std::move(false_case)) {}

	CONDITIONAL(CONDITIONAL const & other) = default;
	CONDITIONAL(CONDITIONAL && move) = default;

	static CONDITIONAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CONDITIONAL_HPP
