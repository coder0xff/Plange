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
	parlex::details::document::text<literal_0x2F0x2F_t> dontCare0;
	
	std::vector<parlex::details::document::text<parlex::details::not_newline_t>> field_1;
	
	parlex::details::document::text<literal_0x0A_t> dontCare2;
	


	explicit END_OF_LINE_COMMENT(
		parlex::details::document::text<literal_0x2F0x2F_t> && dontCare0, std::vector<parlex::details::document::text<parlex::details::not_newline_t>> && field_1, parlex::details::document::text<literal_0x0A_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	END_OF_LINE_COMMENT(END_OF_LINE_COMMENT const & other) = default;
	END_OF_LINE_COMMENT(END_OF_LINE_COMMENT && move) = default;

	static END_OF_LINE_COMMENT build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_END_OF_LINE_COMMENT_HPP
