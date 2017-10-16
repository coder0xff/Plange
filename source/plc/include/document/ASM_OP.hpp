// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_OP_HPP
#define INCLUDED_ASM_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_OP {
	parlex::details::document::built_in_terminal<parlex::details::lowercase_letter_t> field_1;
	
	std::vector<parlex::details::document::built_in_terminal<parlex::details::lowercase_letter_t>> field_2;
	


	explicit ASM_OP(
		parlex::details::document::built_in_terminal<parlex::details::lowercase_letter_t> && field_1, std::vector<parlex::details::document::built_in_terminal<parlex::details::lowercase_letter_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ASM_OP(ASM_OP const & other) = default;
	ASM_OP(ASM_OP && move) = default;

	static ASM_OP build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_OP_HPP
