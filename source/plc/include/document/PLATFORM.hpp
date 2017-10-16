// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLATFORM_HPP
#define INCLUDED_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct PLATFORM {
	std::variant<
		parlex::details::document::built_in_terminal<parlex::details::letter_t>,
		parlex::details::document::built_in_terminal<parlex::details::number_t>
	> field_1;
	
	std::vector<std::variant<
		parlex::details::document::built_in_terminal<parlex::details::letter_t>,
		parlex::details::document::built_in_terminal<parlex::details::number_t>,
		literal___t
	>> field_2;
	


	explicit PLATFORM(
		std::variant<
			parlex::details::document::built_in_terminal<parlex::details::letter_t>,
			parlex::details::document::built_in_terminal<parlex::details::number_t>
		> && field_1, std::vector<std::variant<
			parlex::details::document::built_in_terminal<parlex::details::letter_t>,
			parlex::details::document::built_in_terminal<parlex::details::number_t>,
			literal___t
		>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PLATFORM(PLATFORM const & other) = default;
	PLATFORM(PLATFORM && move) = default;

	static PLATFORM build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_PLATFORM_HPP
