// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RANGE_HPP
#define INCLUDED_RANGE_HPP

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

struct RANGE_1_t {
	std::vector<erased<IC>> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	std::variant<
		literal_0x5D_t,
		literal_0x29_t
	> field_5;
	


	explicit RANGE_1_t(
		std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, std::variant<
			literal_0x5D_t,
			literal_0x29_t
		> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	RANGE_1_t(RANGE_1_t const & other) = default;
	RANGE_1_t(RANGE_1_t && move) = default;

	static RANGE_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

struct RANGE_2_t {
	std::variant<
		literal_0x5B_t,
		literal_0x28_t
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	std::vector<erased<IC>> field_5;
	


	explicit RANGE_2_t(
		std::variant<
			literal_0x5B_t,
			literal_0x28_t
		> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, std::vector<erased<IC>> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	RANGE_2_t(RANGE_2_t const & other) = default;
	RANGE_2_t(RANGE_2_t && move) = default;

	static RANGE_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

struct RANGE_3_t {
	std::variant<
		literal_0x28_t,
		literal_0x5B_t
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	std::vector<erased<IC>> field_5;
	
	erased<EXPRESSION> field_6;
	
	std::vector<erased<IC>> field_7;
	
	std::variant<
		literal_0x5D_t,
		literal_0x29_t
	> field_8;
	


	explicit RANGE_3_t(
		std::variant<
			literal_0x28_t,
			literal_0x5B_t
		> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, std::vector<erased<IC>> && field_5, erased<EXPRESSION> && field_6, std::vector<erased<IC>> && field_7, std::variant<
			literal_0x5D_t,
			literal_0x29_t
		> && field_8) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)), field_8(std::move(field_8)) {}

	RANGE_3_t(RANGE_3_t const & other) = default;
	RANGE_3_t(RANGE_3_t && move) = default;

	static RANGE_3_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

typedef std::variant<
	RANGE_1_t,
	RANGE_2_t,
	RANGE_3_t
> RANGE_base;

struct RANGE: RANGE_base {
	static RANGE build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit RANGE(RANGE_base const & value) : RANGE_base(value) {}
};
} // namespace plc



#endif //INCLUDED_RANGE_HPP
