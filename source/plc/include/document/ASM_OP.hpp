// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_OP_HPP
#define INCLUDED_ASM_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_OP {
	parlex::detail::document::text<parlex::detail::lowercase_letter_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::lowercase_letter_t>> field_2;
	


	explicit ASM_OP(
		parlex::detail::document::text<parlex::detail::lowercase_letter_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::lowercase_letter_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ASM_OP(ASM_OP const & other) = default;
	ASM_OP(ASM_OP && move) = default;

	static ASM_OP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_OP_HPP
