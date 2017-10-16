// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_END_OF_LINE_COMMENT_HPP
#define INCLUDED_END_OF_LINE_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct END_OF_LINE_COMMENT {
	std::vector<parlex::details::document::built_in_terminal<parlex::details::not_newline_t>> field_1;
	


	explicit END_OF_LINE_COMMENT(
		std::vector<parlex::details::document::built_in_terminal<parlex::details::not_newline_t>> && field_1) : field_1(std::move(field_1)) {}

	END_OF_LINE_COMMENT(END_OF_LINE_COMMENT const & other) = default;
	END_OF_LINE_COMMENT(END_OF_LINE_COMMENT && move) = default;

	static END_OF_LINE_COMMENT build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_END_OF_LINE_COMMENT_HPP
