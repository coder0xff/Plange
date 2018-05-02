// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_FRACTIONAL_HPP
#define INCLUDED_NON_FRACTIONAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NON_NEG_NON_FRACTIONAL;

struct NON_FRACTIONAL {
	std::optional<parlex::detail::document::text<literal_0x2D_t>> field_1;
	
	erased<NON_NEG_NON_FRACTIONAL> field_2;
	


	explicit NON_FRACTIONAL(
		std::optional<parlex::detail::document::text<literal_0x2D_t>> && field_1, erased<NON_NEG_NON_FRACTIONAL> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	NON_FRACTIONAL(NON_FRACTIONAL const & other) = default;
	NON_FRACTIONAL(NON_FRACTIONAL && move) = default;

	static NON_FRACTIONAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_NON_FRACTIONAL_HPP
