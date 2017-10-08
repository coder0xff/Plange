// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NEAREST_INTEGER_HPP
#define INCLUDED_NEAREST_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct NEAREST_INTEGER_1_t {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;


	explicit NEAREST_INTEGER_1_t(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2,
		std::vector<erased<IC>> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	NEAREST_INTEGER_1_t(NEAREST_INTEGER_1_t const & other) = default;
	NEAREST_INTEGER_1_t(NEAREST_INTEGER_1_t && move) = default;

	static NEAREST_INTEGER_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

struct NEAREST_INTEGER_2_t {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;


	explicit NEAREST_INTEGER_2_t(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2,
		std::vector<erased<IC>> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	NEAREST_INTEGER_2_t(NEAREST_INTEGER_2_t const & other) = default;
	NEAREST_INTEGER_2_t(NEAREST_INTEGER_2_t && move) = default;

	static NEAREST_INTEGER_2_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

typedef std::variant<
	NEAREST_INTEGER_1_t,
	NEAREST_INTEGER_2_t
> NEAREST_INTEGER_base;

struct NEAREST_INTEGER: NEAREST_INTEGER_base {
	static NEAREST_INTEGER build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit NEAREST_INTEGER(NEAREST_INTEGER_base const & value) : NEAREST_INTEGER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NEAREST_INTEGER_HPP
