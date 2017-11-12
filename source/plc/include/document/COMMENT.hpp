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
	parlex::details::document::text<literal_0x2F0x2A_t> dontCare0;
	
	std::vector<parlex::details::document::text<parlex::details::all_t>> field_1;
	
	parlex::details::document::text<literal_0x2A0x2F_t> dontCare2;
	


	explicit COMMENT(
		parlex::details::document::text<literal_0x2F0x2A_t> && dontCare0, std::vector<parlex::details::document::text<parlex::details::all_t>> && field_1, parlex::details::document::text<literal_0x2A0x2F_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	COMMENT(COMMENT const & other) = default;
	COMMENT(COMMENT && move) = default;

	static COMMENT build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_COMMENT_HPP
