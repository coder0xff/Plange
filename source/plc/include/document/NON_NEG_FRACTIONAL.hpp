// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_FRACTIONAL_HPP
#define INCLUDED_NON_NEG_FRACTIONAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NON_NEG_FRACTIONAL_1_t {
	parlex::details::document::text<parlex::details::decimal_digit_t> field_1;
	
	std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>> field_2;
	
	parlex::details::document::text<literal_0x2E_t> dontCare2;
	
	std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>> field_3;
	


	explicit NON_NEG_FRACTIONAL_1_t(
		parlex::details::document::text<parlex::details::decimal_digit_t> && field_1, std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>> && field_2, parlex::details::document::text<literal_0x2E_t> && dontCare2, std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)), field_3(std::move(field_3)) {}

	NON_NEG_FRACTIONAL_1_t(NON_NEG_FRACTIONAL_1_t const & other) = default;
	NON_NEG_FRACTIONAL_1_t(NON_NEG_FRACTIONAL_1_t && move) = default;

	static NON_NEG_FRACTIONAL_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
};

struct NON_NEG_FRACTIONAL_2_t {
	parlex::details::document::text<literal_0x2E_t> dontCare0;
	
	parlex::details::document::text<parlex::details::decimal_digit_t> field_1;
	
	std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>> field_2;
	


	explicit NON_NEG_FRACTIONAL_2_t(
		parlex::details::document::text<literal_0x2E_t> && dontCare0, parlex::details::document::text<parlex::details::decimal_digit_t> && field_1, std::vector<parlex::details::document::text<parlex::details::decimal_digit_t>> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	NON_NEG_FRACTIONAL_2_t(NON_NEG_FRACTIONAL_2_t const & other) = default;
	NON_NEG_FRACTIONAL_2_t(NON_NEG_FRACTIONAL_2_t && move) = default;

	static NON_NEG_FRACTIONAL_2_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
};

typedef std::variant<
	NON_NEG_FRACTIONAL_1_t,
	NON_NEG_FRACTIONAL_2_t
> NON_NEG_FRACTIONAL_base;

struct NON_NEG_FRACTIONAL: NON_NEG_FRACTIONAL_base {
	static NON_NEG_FRACTIONAL build(parlex::details::ast_node const & n);
	explicit NON_NEG_FRACTIONAL(NON_NEG_FRACTIONAL_base const & value) : NON_NEG_FRACTIONAL_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_NON_NEG_FRACTIONAL_HPP
