// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OCTAL_HPP
#define INCLUDED_OCTAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct OCTAL {
	parlex::detail::document::text<literal_0_t> dontCare0;
	
	parlex::detail::document::text<parlex::detail::octal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>> field_2;
	


	explicit OCTAL(
		parlex::detail::document::text<literal_0_t> && dontCare0, parlex::detail::document::text<parlex::detail::octal_digit_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	OCTAL(OCTAL const & other) = default;
	OCTAL(OCTAL && move) = default;

	static OCTAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_OCTAL_HPP
