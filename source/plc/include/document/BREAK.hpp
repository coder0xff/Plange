// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BREAK_HPP
#define INCLUDED_BREAK_HPP

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
struct IDENTIFIER;

struct BREAK {
	int32_t document_position, consumed_character_count;

	struct field_1_t1 {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> expression;
		
		std::vector<val<IC>> field_3;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t1
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), expression(expression), field_3(field_3), dont_care5(dont_care5) {}
	
		field_1_t1(field_1_t1 const & other) = default;
		static field_1_t1 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t2 {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<IDENTIFIER> identifier;
		
	
	
		explicit field_1_t2
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<IDENTIFIER> const & identifier)
			: field_1(field_1), field_2(field_2), identifier(identifier) {}
	
		field_1_t2(field_1_t2 const & other) = default;
		static field_1_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_break_t> dont_care0;
	
	std::optional<std::variant<
		field_1_t1,
		field_1_t2
	>> field_1;
	


	explicit BREAK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_break_t> const & dont_care0, std::optional<std::variant<
	field_1_t1,
	field_1_t2
>> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	BREAK(BREAK const & other) = default;
	static BREAK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_BREAK_HPP
