// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_HEX_HPP
#define INCLUDED_HEX_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct HEX {
	parlex::details::document::built_in_terminal<parlex::details::hexadecimal_digit_t> field_1;
	
	std::vector<parlex::details::document::built_in_terminal<parlex::details::hexadecimal_digit_t>> field_2;
	


	explicit HEX(
		parlex::details::document::built_in_terminal<parlex::details::hexadecimal_digit_t> && field_1, std::vector<parlex::details::document::built_in_terminal<parlex::details::hexadecimal_digit_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	HEX(HEX const & other) = default;
	HEX(HEX && move) = default;

	static HEX build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_HEX_HPP
