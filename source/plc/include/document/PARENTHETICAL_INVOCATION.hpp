// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_INVOCATION_HPP
#define INCLUDED_PARENTHETICAL_INVOCATION_HPP

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
struct STANDARD_ARGUMENTS;

struct PARENTHETICAL_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<STANDARD_ARGUMENTS> standard_arguments;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit field_1_t
			(val<STANDARD_ARGUMENTS> && standard_arguments, std::vector<val<IC>> && ic)
			: standard_arguments(std::move(standard_arguments)), ic(std::move(ic)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	std::optional<field_1_t> field_1;
	
	parlex::detail::document::text<literal_0x29_t> dont_care3;
	


	explicit PARENTHETICAL_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x28_t> && dont_care0, std::vector<val<IC>> && ic, std::optional<field_1_t> && field_1, parlex::detail::document::text<literal_0x29_t> && dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), ic(std::move(ic)), field_1(std::move(field_1)), dont_care3(std::move(dont_care3)) {}

	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION const & other) = default;
	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION && move) = default;

	static PARENTHETICAL_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PARENTHETICAL_INVOCATION_HPP
