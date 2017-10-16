// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CEILING_HPP
#define INCLUDED_CEILING_HPP

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

struct CEILING_1_t {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	


	explicit CEILING_1_t(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	CEILING_1_t(CEILING_1_t const & other) = default;
	CEILING_1_t(CEILING_1_t && move) = default;

	static CEILING_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

struct CEILING_2_t {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	


	explicit CEILING_2_t(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	CEILING_2_t(CEILING_2_t const & other) = default;
	CEILING_2_t(CEILING_2_t && move) = default;

	static CEILING_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

typedef std::variant<
	CEILING_1_t,
	CEILING_2_t
> CEILING_base;

struct CEILING: CEILING_base {
	static CEILING build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit CEILING(CEILING_base const & value) : CEILING_base(value) {}
};
} // namespace plc



#endif //INCLUDED_CEILING_HPP
