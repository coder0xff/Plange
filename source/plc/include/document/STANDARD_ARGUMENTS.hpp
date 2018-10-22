// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STANDARD_ARGUMENTS_HPP
#define INCLUDED_STANDARD_ARGUMENTS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct STANDARD_ARGUMENTS {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		struct field_1_t {
			std::vector<val<IC>> ic;
			
			std::variant<
				val<EXPRESSION>,
				val<ARGUMENT_PACK>
			> argument;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> const & ic, std::variant<
			val<EXPRESSION>,
			val<ARGUMENT_PACK>
		> const & argument)
				: ic(ic), argument(argument) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<val<IC>> ic;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::optional<field_1_t> field_1;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::optional<field_1_t> const & field_1)
			: ic(ic), dont_care1(dont_care1), field_1(field_1) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<std::variant<
		val<EXPRESSION>,
		val<ARGUMENT_PACK>
	>> head;
	
	std::vector<tail_t> tail;
	


	explicit STANDARD_ARGUMENTS
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<std::variant<
	val<EXPRESSION>,
	val<ARGUMENT_PACK>
>> const & head, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), head(head), tail(tail) {}

	STANDARD_ARGUMENTS(STANDARD_ARGUMENTS const & other) = default;
	static STANDARD_ARGUMENTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_STANDARD_ARGUMENTS_HPP
