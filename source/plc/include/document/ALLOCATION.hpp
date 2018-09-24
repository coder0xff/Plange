// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALLOCATION_HPP
#define INCLUDED_ALLOCATION_HPP

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
struct PARENTHETICAL_INVOCATION;

struct ALLOCATION {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_alloc_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL_INVOCATION> field_2;
	


	explicit ALLOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_alloc_t> && dont_care0, std::vector<val<IC>> && field_1, val<PARENTHETICAL_INVOCATION> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ALLOCATION(ALLOCATION const & other) = default;
	ALLOCATION(ALLOCATION && move) = default;

	static ALLOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ALLOCATION_HPP
