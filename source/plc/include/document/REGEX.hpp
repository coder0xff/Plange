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

struct STRING;

struct REGEX {
	erased<STRING> field_1;
	


	explicit REGEX(
		erased<STRING> && field_1) : field_1(std::move(field_1)) {}

	REGEX(REGEX const & other) = default;
	REGEX(REGEX && move) = default;

	static REGEX build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_REGEX_HPP
