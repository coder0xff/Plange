// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_END_OF_LINE_COMMENT_HPP
#define INCLUDED_END_OF_LINE_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct END_OF_LINE_COMMENT {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2F0x2F_t> dont_care0;
	
	std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>> field_1;
	
	parlex::detail::document::text<literal_0x0A_t> dont_care2;
	


	explicit END_OF_LINE_COMMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2F0x2F_t> const & dont_care0, std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>> const & field_1, parlex::detail::document::text<literal_0x0A_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	END_OF_LINE_COMMENT(END_OF_LINE_COMMENT const & other) = default;
	static END_OF_LINE_COMMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_END_OF_LINE_COMMENT_HPP
