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
		parlex::details::document::text<parlex::details::letter_t>,
		parlex::details::document::text<literal___t>
	> head;
	
	std::vector<std::variant<
		parlex::details::document::text<parlex::details::letter_t>,
		parlex::details::document::text<parlex::details::number_t>,
		parlex::details::document::text<literal___t>
	>> tail;
	


	explicit IDENTIFIER(
		std::variant<
			parlex::details::document::text<parlex::details::letter_t>,
			parlex::details::document::text<literal___t>
		> && head, std::vector<std::variant<
			parlex::details::document::text<parlex::details::letter_t>,
			parlex::details::document::text<parlex::details::number_t>,
			parlex::details::document::text<literal___t>
		>> && tail) : head(std::move(head)), tail(std::move(tail)) {}

	IDENTIFIER(IDENTIFIER const & other) = default;
	IDENTIFIER(IDENTIFIER && move) = default;

	static IDENTIFIER build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_IDENTIFIER_HPP
