// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_HPP
#define INCLUDED_ARRAY_HPP

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

struct ARRAY {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_1_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<EXPRESSION> expression;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<val<IC>> && field_2, val<EXPRESSION> && expression)
				: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), expression(std::move(expression)) {}
		
			field_1_t(field_1_t const & other) = default;
			field_1_t(field_1_t && move) = default;
		
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<EXPRESSION> expression;
		
		std::vector<field_1_t> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(val<EXPRESSION> && expression, std::vector<field_1_t> && field_1, std::vector<val<IC>> && field_2)
			: expression(std::move(expression)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<field_2_t> field_2;
	
	parlex::detail::document::text<literal_0x5D_t> dont_care3;
	


	explicit ARRAY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x5B_t> && dont_care0, std::vector<val<IC>> && field_1, std::optional<field_2_t> && field_2, parlex::detail::document::text<literal_0x5D_t> && dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care3(std::move(dont_care3)) {}

	ARRAY(ARRAY const & other) = default;
	ARRAY(ARRAY && move) = default;

	static ARRAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARRAY_HPP
