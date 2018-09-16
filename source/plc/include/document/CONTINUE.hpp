// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONTINUE_HPP
#define INCLUDED_CONTINUE_HPP

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
struct IDENTIFIER;

struct CONTINUE {
	int32_t document_position, consumed_character_count;

	struct field_1_t1 {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> expression;
		
		std::vector<erased<IC>> field_3;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t1
			(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5B_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x5D_t> && dont_care5)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), expression(std::move(expression)), field_3(std::move(field_3)), dont_care5(std::move(dont_care5)) {}
	
		field_1_t1(field_1_t1 const & other) = default;
		field_1_t1(field_1_t1 && move) = default;
	
		static field_1_t1 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t2 {
		erased<IC> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<IDENTIFIER> identifier;
		
	
	
		explicit field_1_t2
			(erased<IC> && field_1, std::vector<erased<IC>> && field_2, erased<IDENTIFIER> && identifier)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), identifier(std::move(identifier)) {}
	
		field_1_t2(field_1_t2 const & other) = default;
		field_1_t2(field_1_t2 && move) = default;
	
		static field_1_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_continue_t> dont_care0;
	
	std::optional<std::variant<
		field_1_t1,
		field_1_t2
	>> field_1;
	


	explicit CONTINUE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_continue_t> && dont_care0, std::optional<std::variant<
	field_1_t1,
	field_1_t2
>> && field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)) {}

	CONTINUE(CONTINUE const & other) = default;
	CONTINUE(CONTINUE && move) = default;

	static CONTINUE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CONTINUE_HPP
