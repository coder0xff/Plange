// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_DECLARATION_HPP
#define INCLUDED_TYPE_SCOPE_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct IDENTIFIER;
struct MEMBER_OFFSET;
struct XML_DOC_STRING;

struct TYPE_SCOPE_DECLARATION {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<XML_DOC_STRING> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(val<XML_DOC_STRING> && field_1, std::vector<val<IC>> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t {
		std::vector<val<IC>> field_1;
		
		val<MEMBER_OFFSET> field_2;
		
	
	
		explicit field_3_t
			(std::vector<val<IC>> && field_1, val<MEMBER_OFFSET> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_3_t(field_3_t const & other) = default;
		field_3_t(field_3_t && move) = default;
	
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	val<IDENTIFIER> field_2;
	
	std::optional<field_3_t> field_3;
	


	explicit TYPE_SCOPE_DECLARATION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> && field_1, val<IDENTIFIER> && field_2, std::optional<field_3_t> && field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	TYPE_SCOPE_DECLARATION(TYPE_SCOPE_DECLARATION const & other) = default;
	TYPE_SCOPE_DECLARATION(TYPE_SCOPE_DECLARATION && move) = default;

	static TYPE_SCOPE_DECLARATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_DECLARATION_HPP
