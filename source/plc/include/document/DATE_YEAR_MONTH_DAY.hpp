// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_YEAR_MONTH_DAY_HPP
#define INCLUDED_DATE_YEAR_MONTH_DAY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE_YEAR_MONTH_DAY {
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_1;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_2;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_3;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_4;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_5;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_6;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_7;
	
	parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> field_8;
	


	explicit DATE_YEAR_MONTH_DAY(
		parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_1, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_2, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_3, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_4, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_5, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_6, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_7, parlex::details::document::built_in_terminal<parlex::details::decimal_digit_t> && field_8) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)), field_8(std::move(field_8)) {}

	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY const & other) = default;
	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY && move) = default;

	static DATE_YEAR_MONTH_DAY build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DATE_YEAR_MONTH_DAY_HPP
