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
	literal_1_t,
	literal_2_t,
	literal_3_t,
	literal_4_t,
	literal_5_t,
	literal_6_t,
	literal_7_t,
	literal_8_t,
	literal_9_t
> NON_ZERO_DECIMAL_DIGIT_base;

struct NON_ZERO_DECIMAL_DIGIT: NON_ZERO_DECIMAL_DIGIT_base {
	static NON_ZERO_DECIMAL_DIGIT build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit NON_ZERO_DECIMAL_DIGIT(NON_ZERO_DECIMAL_DIGIT_base const & value) : NON_ZERO_DECIMAL_DIGIT_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
