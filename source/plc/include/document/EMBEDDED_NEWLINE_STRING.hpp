// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;

struct EMBEDDED_NEWLINE_STRING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x220x220x22_t> dont_care0;
	
	erased<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x220x220x22_t> dont_care2;
	


	explicit EMBEDDED_NEWLINE_STRING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x220x220x22_t> && dont_care0, erased<EMBEDDED_NEWLINE_STRING_INTERIOR> && field_1, parlex::detail::document::text<literal_0x220x220x22_t> && dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)) {}

	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING const & other) = default;
	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING && move) = default;

	static EMBEDDED_NEWLINE_STRING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
