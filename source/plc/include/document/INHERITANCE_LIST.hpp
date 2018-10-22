// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_LIST_HPP
#define INCLUDED_INHERITANCE_LIST_HPP

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
struct INHERITANCE_ITEM_PREFIX;

struct INHERITANCE_LIST {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		std::optional<val<INHERITANCE_ITEM_PREFIX>> field_3;
		
		val<EXPRESSION> expression;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, std::optional<val<INHERITANCE_ITEM_PREFIX>> const & field_3, val<EXPRESSION> const & expression)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), expression(expression) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<INHERITANCE_ITEM_PREFIX>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<field_2_t> field_2;
	


	explicit INHERITANCE_LIST
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<INHERITANCE_ITEM_PREFIX>> const & field_1, val<EXPRESSION> const & expression, std::vector<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), expression(expression), field_2(field_2) {}

	INHERITANCE_LIST(INHERITANCE_LIST const & other) = default;
	static INHERITANCE_LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_INHERITANCE_LIST_HPP
