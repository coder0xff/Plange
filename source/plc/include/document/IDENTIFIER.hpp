// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IDENTIFIER_HPP
#define INCLUDED_IDENTIFIER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IDENTIFIER {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<literal___t>
	> head;
	
	std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>> tail;
	


	explicit IDENTIFIER
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<literal___t>
> const & head, std::vector<std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<parlex::detail::number_t>,
	parlex::detail::document::text<literal___t>
>> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), head(head), tail(tail) {}

	IDENTIFIER(IDENTIFIER const & other) = default;
	static IDENTIFIER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_IDENTIFIER_HPP
