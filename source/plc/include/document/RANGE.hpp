// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RANGE_HPP
#define INCLUDED_RANGE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct RANGE_1_t {
	parlex::detail::document::text<literal_0x28_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dontCare2;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	> field_5;
	


	explicit RANGE_1_t(
		parlex::detail::document::text<literal_0x28_t> && dontCare0, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dontCare2, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, std::variant<
			parlex::detail::document::text<literal_0x5D_t>,
			parlex::detail::document::text<literal_0x29_t>
		> && field_5) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	RANGE_1_t(RANGE_1_t const & other) = default;
	RANGE_1_t(RANGE_1_t && move) = default;

	static RANGE_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct RANGE_2_t {
	std::variant<
		parlex::detail::document::text<literal_0x5B_t>,
		parlex::detail::document::text<literal_0x28_t>
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dontCare4;
	
	std::vector<erased<IC>> field_5;
	
	parlex::detail::document::text<literal_0x29_t> dontCare6;
	


	explicit RANGE_2_t(
		std::variant<
			parlex::detail::document::text<literal_0x5B_t>,
			parlex::detail::document::text<literal_0x28_t>
		> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dontCare4, std::vector<erased<IC>> && field_5, parlex::detail::document::text<literal_0x29_t> && dontCare6) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare4(std::move(dontCare4)), field_5(std::move(field_5)), dontCare6(std::move(dontCare6)) {}

	RANGE_2_t(RANGE_2_t const & other) = default;
	RANGE_2_t(RANGE_2_t && move) = default;

	static RANGE_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct RANGE_3_t {
	std::variant<
		parlex::detail::document::text<literal_0x28_t>,
		parlex::detail::document::text<literal_0x5B_t>
	> field_01;
	
	std::vector<erased<IC>> field_02;
	
	erased<EXPRESSION> field_03;
	
	std::vector<erased<IC>> field_04;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dontCare4;
	
	std::vector<erased<IC>> field_05;
	
	erased<EXPRESSION> field_06;
	
	std::vector<erased<IC>> field_07;
	
	std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	> field_08;
	


	explicit RANGE_3_t(
		std::variant<
			parlex::detail::document::text<literal_0x28_t>,
			parlex::detail::document::text<literal_0x5B_t>
		> && field_01, std::vector<erased<IC>> && field_02, erased<EXPRESSION> && field_03, std::vector<erased<IC>> && field_04, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dontCare4, std::vector<erased<IC>> && field_05, erased<EXPRESSION> && field_06, std::vector<erased<IC>> && field_07, std::variant<
			parlex::detail::document::text<literal_0x5D_t>,
			parlex::detail::document::text<literal_0x29_t>
		> && field_08) : field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), dontCare4(std::move(dontCare4)), field_05(std::move(field_05)), field_06(std::move(field_06)), field_07(std::move(field_07)), field_08(std::move(field_08)) {}

	RANGE_3_t(RANGE_3_t const & other) = default;
	RANGE_3_t(RANGE_3_t && move) = default;

	static RANGE_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	RANGE_1_t,
	RANGE_2_t,
	RANGE_3_t
> RANGE_base;

struct RANGE: RANGE_base {
	static RANGE build(parlex::detail::ast_node const & n);
	explicit RANGE(RANGE_base const & value) : RANGE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_RANGE_HPP
