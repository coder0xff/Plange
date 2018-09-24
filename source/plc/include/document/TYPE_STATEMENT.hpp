// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_STATEMENT_HPP
#define INCLUDED_TYPE_STATEMENT_HPP

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
struct STATEMENT;
struct TYPE_SCOPE_TYPE_CONSTRAINT;
struct VISIBILITY_MODIFIER;

struct TYPE_STATEMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t1 {
		val<VISIBILITY_MODIFIER> field_1;
		
		std::vector<val<IC>> field_2;
		
		parlex::detail::document::text<literal_0x3A_t> dont_care2;
		
	
	
		explicit field_1_t1
			(val<VISIBILITY_MODIFIER> && field_1, std::vector<val<IC>> && field_2, parlex::detail::document::text<literal_0x3A_t> && dont_care2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care2(std::move(dont_care2)) {}
	
		field_1_t1(field_1_t1 const & other) = default;
		field_1_t1(field_1_t1 && move) = default;
	
		static field_1_t1 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		field_1_t1,
		val<TYPE_SCOPE_TYPE_CONSTRAINT>,
		val<STATEMENT>
	> field_1;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care1;
	


	explicit TYPE_STATEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	field_1_t1,
	val<TYPE_SCOPE_TYPE_CONSTRAINT>,
	val<STATEMENT>
> && field_1, parlex::detail::document::text<literal_0x3B_t> && dont_care1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), dont_care1(std::move(dont_care1)) {}

	TYPE_STATEMENT(TYPE_STATEMENT const & other) = default;
	TYPE_STATEMENT(TYPE_STATEMENT && move) = default;

	static TYPE_STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_STATEMENT_HPP
