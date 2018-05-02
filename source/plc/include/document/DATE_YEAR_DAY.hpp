// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_YEAR_DAY_HPP
#define INCLUDED_DATE_YEAR_DAY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE_YEAR_DAY {
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_3;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_4;
	
	parlex::detail::document::text<literal_0x2D_t> dontCare4;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_5;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_6;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_7;
	


	explicit DATE_YEAR_DAY(
		parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_2, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_3, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_4, parlex::detail::document::text<literal_0x2D_t> && dontCare4, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_5, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_6, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_7) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare4(std::move(dontCare4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)) {}

	DATE_YEAR_DAY(DATE_YEAR_DAY const & other) = default;
	DATE_YEAR_DAY(DATE_YEAR_DAY && move) = default;

	static DATE_YEAR_DAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DATE_YEAR_DAY_HPP
