// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_REGEX_HPP
#define INCLUDED_REGEX_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct REGEX {
	parlex::details::document::text<literal_R_t> dontCare0;
	
	parlex::details::document::text<void> field_1;
	


	explicit REGEX(
		parlex::details::document::text<literal_R_t> && dontCare0, parlex::details::document::text<void> && field_1) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)) {}

	REGEX(REGEX const & other) = default;
	REGEX(REGEX && move) = default;

	static REGEX build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_REGEX_HPP
