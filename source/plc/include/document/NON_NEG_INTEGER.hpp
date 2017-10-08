// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_INTEGER_HPP
#define INCLUDED_NON_NEG_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NON_ZERO_DECIMAL_DIGIT;

struct NON_NEG_INTEGER_1_t {
	erased<NON_ZERO_DECIMAL_DIGIT> field_1;
	int field_2;


	explicit NON_NEG_INTEGER_1_t(
		erased<NON_ZERO_DECIMAL_DIGIT> && field_1,
		int && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	NON_NEG_INTEGER_1_t(NON_NEG_INTEGER_1_t const & other) = default;
	NON_NEG_INTEGER_1_t(NON_NEG_INTEGER_1_t && move) = default;

	static NON_NEG_INTEGER_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

typedef std::variant<
	NON_NEG_INTEGER_1_t,
	literal_0_t
> NON_NEG_INTEGER_base;

struct NON_NEG_INTEGER: NON_NEG_INTEGER_base {
	static NON_NEG_INTEGER build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit NON_NEG_INTEGER(NON_NEG_INTEGER_base const & value) : NON_NEG_INTEGER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NON_NEG_INTEGER_HPP
