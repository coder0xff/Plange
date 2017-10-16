// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct FLOOR_1_t {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::vector<erased<IC>> field_2;
	


	explicit FLOOR_1_t(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	FLOOR_1_t(FLOOR_1_t const & other) = default;
	FLOOR_1_t(FLOOR_1_t && move) = default;

	static FLOOR_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

struct FLOOR_2_t {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::vector<erased<IC>> field_2;
	


	explicit FLOOR_2_t(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	FLOOR_2_t(FLOOR_2_t const & other) = default;
	FLOOR_2_t(FLOOR_2_t && move) = default;

	static FLOOR_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

typedef std::variant<
	FLOOR_1_t,
	FLOOR_2_t
> FLOOR_base;

struct FLOOR: FLOOR_base {
	static FLOOR build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit FLOOR(FLOOR_base const & value) : FLOOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FLOOR_HPP
