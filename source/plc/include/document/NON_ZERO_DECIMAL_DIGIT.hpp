// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
#define INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef std::variant<
	parlex::details::document::text<literal_1_t>,
	parlex::details::document::text<literal_2_t>,
	parlex::details::document::text<literal_3_t>,
	parlex::details::document::text<literal_4_t>,
	parlex::details::document::text<literal_5_t>,
	parlex::details::document::text<literal_6_t>,
	parlex::details::document::text<literal_7_t>,
	parlex::details::document::text<literal_8_t>,
	parlex::details::document::text<literal_9_t>
> NON_ZERO_DECIMAL_DIGIT_base;

struct NON_ZERO_DECIMAL_DIGIT: NON_ZERO_DECIMAL_DIGIT_base {
	static NON_ZERO_DECIMAL_DIGIT build(parlex::details::ast_node const & n);
	explicit NON_ZERO_DECIMAL_DIGIT(NON_ZERO_DECIMAL_DIGIT_base const & value) : NON_ZERO_DECIMAL_DIGIT_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
