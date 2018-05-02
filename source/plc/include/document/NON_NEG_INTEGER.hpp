// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_INTEGER_HPP
#define INCLUDED_NON_NEG_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NON_ZERO_DECIMAL_DIGIT;

struct NON_NEG_INTEGER_1_t {
	erased<NON_ZERO_DECIMAL_DIGIT> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
	


	explicit NON_NEG_INTEGER_1_t(
		erased<NON_ZERO_DECIMAL_DIGIT> && field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	NON_NEG_INTEGER_1_t(NON_NEG_INTEGER_1_t const & other) = default;
	NON_NEG_INTEGER_1_t(NON_NEG_INTEGER_1_t && move) = default;

	static NON_NEG_INTEGER_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	NON_NEG_INTEGER_1_t,
	parlex::detail::document::text<literal_0_t>
> NON_NEG_INTEGER_base;

struct NON_NEG_INTEGER: NON_NEG_INTEGER_base {
	static NON_NEG_INTEGER build(parlex::detail::ast_node const & n);
	explicit NON_NEG_INTEGER(NON_NEG_INTEGER_base const & value) : NON_NEG_INTEGER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_NON_NEG_INTEGER_HPP
