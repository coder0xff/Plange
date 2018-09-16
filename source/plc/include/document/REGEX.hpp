// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_REGEX_HPP
#define INCLUDED_REGEX_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct REGEX {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_R_t> dont_care0;
	
	parlex::detail::document::text<void> field_1;
	


	explicit REGEX
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_R_t> && dont_care0, parlex::detail::document::text<void> && field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)) {}

	REGEX(REGEX const & other) = default;
	REGEX(REGEX && move) = default;

	static REGEX build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_REGEX_HPP
