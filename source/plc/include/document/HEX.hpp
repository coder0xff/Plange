// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_HEX_HPP
#define INCLUDED_HEX_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct HEX {
	parlex::detail::document::text<literal_0x_t> dontCare0;
	
	parlex::detail::document::text<parlex::detail::hexadecimal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>> field_2;
	


	explicit HEX(
		parlex::detail::document::text<literal_0x_t> && dontCare0, parlex::detail::document::text<parlex::detail::hexadecimal_digit_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	HEX(HEX const & other) = default;
	HEX(HEX && move) = default;

	static HEX build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_HEX_HPP
