// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IDENTIFIER_HPP
#define INCLUDED_IDENTIFIER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IDENTIFIER {
	std::variant<
		parlex::details::document::built_in_terminal<parlex::details::letter_t>,
		literal___t
	> head;
	
	std::vector<std::variant<
		parlex::details::document::built_in_terminal<parlex::details::letter_t>,
		parlex::details::document::built_in_terminal<parlex::details::number_t>,
		literal___t
	>> tail;
	


	explicit IDENTIFIER(
		std::variant<
			parlex::details::document::built_in_terminal<parlex::details::letter_t>,
			literal___t
		> && head, std::vector<std::variant<
			parlex::details::document::built_in_terminal<parlex::details::letter_t>,
			parlex::details::document::built_in_terminal<parlex::details::number_t>,
			literal___t
		>> && tail) : head(std::move(head)), tail(std::move(tail)) {}

	IDENTIFIER(IDENTIFIER const & other) = default;
	IDENTIFIER(IDENTIFIER && move) = default;

	static IDENTIFIER build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_IDENTIFIER_HPP
