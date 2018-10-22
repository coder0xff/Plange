// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONDITIONAL_HPP
#define INCLUDED_CONDITIONAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct CONDITIONAL {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> condition;
	
	std::vector<val<IC>> field_01;
	
	parlex::detail::document::text<literal_0x3F_t> dont_care2;
	
	std::vector<val<IC>> field_02;
	
	val<EXPRESSION> true_case;
	
	std::vector<val<IC>> field_03;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care6;
	
	std::vector<val<IC>> field_04;
	
	val<EXPRESSION> false_case;
	


	explicit CONDITIONAL
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & condition, std::vector<val<IC>> const & field_01, parlex::detail::document::text<literal_0x3F_t> const & dont_care2, std::vector<val<IC>> const & field_02, val<EXPRESSION> const & true_case, std::vector<val<IC>> const & field_03, parlex::detail::document::text<literal_0x3A_t> const & dont_care6, std::vector<val<IC>> const & field_04, val<EXPRESSION> const & false_case)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), condition(condition), field_01(field_01), dont_care2(dont_care2), field_02(field_02), true_case(true_case), field_03(field_03), dont_care6(dont_care6), field_04(field_04), false_case(false_case) {}

	CONDITIONAL(CONDITIONAL const & other) = default;
	static CONDITIONAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CONDITIONAL_HPP
