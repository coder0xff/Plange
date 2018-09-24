// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_HEAD_HPP
#define INCLUDED_TYPE_CONSTRAINT_HEAD_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ATTRIBUTE;
struct EXTERN;
struct IC;
struct IMPLICIT_TYPE_DEREFERENCE;
struct STATIC;
struct TYPE_DEREFERENCE;
struct VISIBILITY_MODIFIER;
struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
struct VOLATILE_TYPE_DEREFERENCE;
struct XML_DOC_STRING;

struct TYPE_CONSTRAINT_HEAD {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<XML_DOC_STRING> xml_doc_string;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit field_1_t
			(val<XML_DOC_STRING> && xml_doc_string, std::vector<val<IC>> && field_1)
			: xml_doc_string(std::move(xml_doc_string)), field_1(std::move(field_1)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		val<ATTRIBUTE> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(val<ATTRIBUTE> && field_1, std::vector<val<IC>> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t {
		val<VISIBILITY_MODIFIER> visibility_modifier;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit field_3_t
			(val<VISIBILITY_MODIFIER> && visibility_modifier, std::vector<val<IC>> && field_1)
			: visibility_modifier(std::move(visibility_modifier)), field_1(std::move(field_1)) {}
	
		field_3_t(field_3_t const & other) = default;
		field_3_t(field_3_t && move) = default;
	
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t {
		val<STATIC> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_4_t
			(val<STATIC> && field_1, std::vector<val<IC>> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t(field_4_t const & other) = default;
		field_4_t(field_4_t && move) = default;
	
		static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_5_t {
		val<EXTERN> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_5_t
			(val<EXTERN> && field_1, std::vector<val<IC>> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_5_t(field_5_t const & other) = default;
		field_5_t(field_5_t && move) = default;
	
		static field_5_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	std::vector<field_2_t> field_2;
	
	std::optional<field_3_t> field_3;
	
	std::optional<field_4_t> field_4;
	
	std::optional<field_5_t> field_5;
	
	std::variant<
		val<TYPE_DEREFERENCE>,
		val<VOLATILE_TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>,
		val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	> type_dereference;
	


	explicit TYPE_CONSTRAINT_HEAD
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> && field_1, std::vector<field_2_t> && field_2, std::optional<field_3_t> && field_3, std::optional<field_4_t> && field_4, std::optional<field_5_t> && field_5, std::variant<
	val<TYPE_DEREFERENCE>,
	val<VOLATILE_TYPE_DEREFERENCE>,
	val<IMPLICIT_TYPE_DEREFERENCE>,
	val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
> && type_dereference)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), type_dereference(std::move(type_dereference)) {}

	TYPE_CONSTRAINT_HEAD(TYPE_CONSTRAINT_HEAD const & other) = default;
	TYPE_CONSTRAINT_HEAD(TYPE_CONSTRAINT_HEAD && move) = default;

	static TYPE_CONSTRAINT_HEAD build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_HEAD_HPP
