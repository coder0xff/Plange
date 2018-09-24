// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DO_HPP
#define INCLUDED_DO_HPP

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
struct PARENTHETICAL;

struct DO {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		std::variant<
			parlex::detail::document::text<literal_while_t>,
			parlex::detail::document::text<literal_until_t>
		> field_2;
		
		std::vector<val<IC>> field_3;
		
		val<PARENTHETICAL> condition;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> && field_1, std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	> && field_2, std::vector<val<IC>> && field_3, val<PARENTHETICAL> && condition)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), condition(std::move(condition)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_do_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit DO
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_do_t> && dont_care0, std::vector<val<IC>> && field_1, val<EXPRESSION> && expression, std::optional<field_2_t> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	DO(DO const & other) = default;
	DO(DO && move) = default;

	static DO build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DO_HPP
