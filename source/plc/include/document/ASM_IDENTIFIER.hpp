// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_IDENTIFIER_HPP
#define INCLUDED_ASM_IDENTIFIER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IDENTIFIER;

struct ASM_IDENTIFIER {
	std::optional<parlex::detail::document::text<literal_0x25_t>> field_1;
	
	erased<IDENTIFIER> field_2;
	


	explicit ASM_IDENTIFIER(
		std::optional<parlex::detail::document::text<literal_0x25_t>> && field_1, erased<IDENTIFIER> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ASM_IDENTIFIER(ASM_IDENTIFIER const & other) = default;
	ASM_IDENTIFIER(ASM_IDENTIFIER && move) = default;

	static ASM_IDENTIFIER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_IDENTIFIER_HPP
