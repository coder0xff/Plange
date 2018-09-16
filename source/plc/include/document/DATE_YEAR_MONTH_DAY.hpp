// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_YEAR_MONTH_DAY_HPP
#define INCLUDED_DATE_YEAR_MONTH_DAY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE_YEAR_MONTH_DAY {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_01;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_02;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_03;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_04;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care4;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_05;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_06;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care7;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_07;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_08;
	


	explicit DATE_YEAR_MONTH_DAY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_01, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_02, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_03, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_04, parlex::detail::document::text<literal_0x2D_t> && dont_care4, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_05, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_06, parlex::detail::document::text<literal_0x2D_t> && dont_care7, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_07, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_08)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), dont_care4(std::move(dont_care4)), field_05(std::move(field_05)), field_06(std::move(field_06)), dont_care7(std::move(dont_care7)), field_07(std::move(field_07)), field_08(std::move(field_08)) {}

	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY const & other) = default;
	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY && move) = default;

	static DATE_YEAR_MONTH_DAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DATE_YEAR_MONTH_DAY_HPP
