// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct DECLARATION;
struct DEFINITION;
struct IC;
struct TYPE_CONSTRAINT_CHAIN;

struct TYPE_CONSTRAINT_CHAIN {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::vector<erased<IC>> field_2;
		
		erased<TYPE_CONSTRAINT_CHAIN> field_3;
		
	
	
		explicit field_2_t
			(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<TYPE_CONSTRAINT_CHAIN> && field_3)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		erased<DECLARATION>,
		erased<ASSIGNMENT_CHAIN>,
		erased<DEFINITION>
	> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit TYPE_CONSTRAINT_CHAIN
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	erased<DECLARATION>,
	erased<ASSIGNMENT_CHAIN>,
	erased<DEFINITION>
> && field_1, std::optional<field_2_t> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	TYPE_CONSTRAINT_CHAIN(TYPE_CONSTRAINT_CHAIN const & other) = default;
	TYPE_CONSTRAINT_CHAIN(TYPE_CONSTRAINT_CHAIN && move) = default;

	static TYPE_CONSTRAINT_CHAIN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
