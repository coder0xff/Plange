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
struct XML_DOC_STRING;

struct ENUM_ELEMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3A0x3D_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> expression;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x3A0x3D_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), expression(expression) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<XML_DOC_STRING>> doc;
	
	val<IDENTIFIER> identifier;
	
	std::optional<field_1_t> field_1;
	


	explicit ENUM_ELEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<XML_DOC_STRING>> const & doc, val<IDENTIFIER> const & identifier, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), doc(doc), identifier(identifier), field_1(field_1) {}

	ENUM_ELEMENT(ENUM_ELEMENT const & other) = default;
	static ENUM_ELEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ENUM_ELEMENT_HPP
