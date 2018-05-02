// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
#define INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef std::variant<
	parlex::detail::document::text<literal_1_t>,
	parlex::detail::document::text<literal_2_t>,
	parlex::detail::document::text<literal_3_t>,
	parlex::detail::document::text<literal_4_t>,
	parlex::detail::document::text<literal_5_t>,
	parlex::detail::document::text<literal_6_t>,
	parlex::detail::document::text<literal_7_t>,
	parlex::detail::document::text<literal_8_t>,
	parlex::detail::document::text<literal_9_t>
> NON_ZERO_DECIMAL_DIGIT_base;

struct NON_ZERO_DECIMAL_DIGIT: NON_ZERO_DECIMAL_DIGIT_base {
	static NON_ZERO_DECIMAL_DIGIT build(parlex::detail::ast_node const & n);
	explicit NON_ZERO_DECIMAL_DIGIT(NON_ZERO_DECIMAL_DIGIT_base const & value) : NON_ZERO_DECIMAL_DIGIT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
