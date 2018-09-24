// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_ELEMENT_HPP
#define INCLUDED_ENUM_ELEMENT_HPP

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

struct ENUM_ELEMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3A0x3D_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> expression;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> && field_1, parlex::detail::document::text<literal_0x3A0x3D_t> && dont_care1, std::vector<val<IC>> && field_2, val<EXPRESSION> && expression)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), expression(std::move(expression)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER> identifier;
	
	std::optional<field_1_t> field_1;
	


	explicit ENUM_ELEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER> && identifier, std::optional<field_1_t> && field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier(std::move(identifier)), field_1(std::move(field_1)) {}

	ENUM_ELEMENT(ENUM_ELEMENT const & other) = default;
	ENUM_ELEMENT(ENUM_ELEMENT && move) = default;

	static ENUM_ELEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ENUM_ELEMENT_HPP
