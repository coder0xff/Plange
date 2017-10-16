// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMMENT_HPP
#define INCLUDED_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct COMMENT {
	std::vector<parlex::details::document::built_in_terminal<parlex::details::all_t>> field_1;
	


	explicit COMMENT(
		std::vector<parlex::details::document::built_in_terminal<parlex::details::all_t>> && field_1) : field_1(std::move(field_1)) {}

	COMMENT(COMMENT const & other) = default;
	COMMENT(COMMENT && move) = default;

	static COMMENT build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_COMMENT_HPP
