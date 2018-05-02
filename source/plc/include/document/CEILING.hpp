// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CEILING_HPP
#define INCLUDED_CEILING_HPP

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

struct CEILING_1_t {
	parlex::detail::document::text<literal_0xE20x8C0x88_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0xE20x8C0x89_t> dontCare4;
	


	explicit CEILING_1_t(
		parlex::detail::document::text<literal_0xE20x8C0x88_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0xE20x8C0x89_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare4(std::move(dontCare4)) {}

	CEILING_1_t(CEILING_1_t const & other) = default;
	CEILING_1_t(CEILING_1_t && move) = default;

	static CEILING_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct CEILING_2_t {
	parlex::detail::document::text<literal_0x7C0x27_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0x270x7C_t> dontCare4;
	


	explicit CEILING_2_t(
		parlex::detail::document::text<literal_0x7C0x27_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x270x7C_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare4(std::move(dontCare4)) {}

	CEILING_2_t(CEILING_2_t const & other) = default;
	CEILING_2_t(CEILING_2_t && move) = default;

	static CEILING_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	CEILING_1_t,
	CEILING_2_t
> CEILING_base;

struct CEILING: CEILING_base {
	static CEILING build(parlex::detail::ast_node const & n);
	explicit CEILING(CEILING_base const & value) : CEILING_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_CEILING_HPP
