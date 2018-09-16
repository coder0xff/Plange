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

struct RANGE1_t {
	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care2;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	> field_5;
	


	explicit RANGE1_t
		(parlex::detail::document::text<literal_0x28_t> && dont_care0, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dont_care2, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, std::variant<
	parlex::detail::document::text<literal_0x5D_t>,
	parlex::detail::document::text<literal_0x29_t>
> && field_5)
		: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	RANGE1_t(RANGE1_t const & other) = default;
	RANGE1_t(RANGE1_t && move) = default;

	static RANGE1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct RANGE2_t {
	std::variant<
		parlex::detail::document::text<literal_0x5B_t>,
		parlex::detail::document::text<literal_0x28_t>
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care4;
	
	std::vector<erased<IC>> field_5;
	
	parlex::detail::document::text<literal_0x29_t> dont_care6;
	


	explicit RANGE2_t
		(std::variant<
	parlex::detail::document::text<literal_0x5B_t>,
	parlex::detail::document::text<literal_0x28_t>
> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dont_care4, std::vector<erased<IC>> && field_5, parlex::detail::document::text<literal_0x29_t> && dont_care6)
		: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dont_care4(std::move(dont_care4)), field_5(std::move(field_5)), dont_care6(std::move(dont_care6)) {}

	RANGE2_t(RANGE2_t const & other) = default;
	RANGE2_t(RANGE2_t && move) = default;

	static RANGE2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct RANGE3_t {
	std::variant<
		parlex::detail::document::text<literal_0x28_t>,
		parlex::detail::document::text<literal_0x5B_t>
	> field_01;
	
	std::vector<erased<IC>> field_02;
	
	erased<EXPRESSION> field_03;
	
	std::vector<erased<IC>> field_04;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care4;
	
	std::vector<erased<IC>> field_05;
	
	erased<EXPRESSION> field_06;
	
	std::vector<erased<IC>> field_07;
	
	std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	> field_08;
	


	explicit RANGE3_t
		(std::variant<
	parlex::detail::document::text<literal_0x28_t>,
	parlex::detail::document::text<literal_0x5B_t>
> && field_01, std::vector<erased<IC>> && field_02, erased<EXPRESSION> && field_03, std::vector<erased<IC>> && field_04, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dont_care4, std::vector<erased<IC>> && field_05, erased<EXPRESSION> && field_06, std::vector<erased<IC>> && field_07, std::variant<
	parlex::detail::document::text<literal_0x5D_t>,
	parlex::detail::document::text<literal_0x29_t>
> && field_08)
		: field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), dont_care4(std::move(dont_care4)), field_05(std::move(field_05)), field_06(std::move(field_06)), field_07(std::move(field_07)), field_08(std::move(field_08)) {}

	RANGE3_t(RANGE3_t const & other) = default;
	RANGE3_t(RANGE3_t && move) = default;

	static RANGE3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	RANGE1_t,
	RANGE2_t,
	RANGE3_t
> RANGE_base;

struct RANGE: RANGE_base {
	static RANGE build(parlex::detail::ast_node const & n);
	explicit RANGE(RANGE_base const & value) : RANGE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_RANGE_HPP
