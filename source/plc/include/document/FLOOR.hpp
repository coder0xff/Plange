// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

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

struct FLOOR_1_t {
	parlex::detail::document::text<literal_0xE20x8C0x8A_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x8C0x8B_t> dontCare4;
	


	explicit FLOOR_1_t(
		parlex::detail::document::text<literal_0xE20x8C0x8A_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0xE20x8C0x8B_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)), dontCare4(std::move(dontCare4)) {}

	FLOOR_1_t(FLOOR_1_t const & other) = default;
	FLOOR_1_t(FLOOR_1_t && move) = default;

	static FLOOR_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct FLOOR_2_t {
	parlex::detail::document::text<literal_0x7C__t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal__0x7C_t> dontCare4;
	


	explicit FLOOR_2_t(
		parlex::detail::document::text<literal_0x7C__t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal__0x7C_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)), dontCare4(std::move(dontCare4)) {}

	FLOOR_2_t(FLOOR_2_t const & other) = default;
	FLOOR_2_t(FLOOR_2_t && move) = default;

	static FLOOR_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	FLOOR_1_t,
	FLOOR_2_t
> FLOOR_base;

struct FLOOR: FLOOR_base {
	static FLOOR build(parlex::detail::ast_node const & n);
	explicit FLOOR(FLOOR_base const & value) : FLOOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_FLOOR_HPP
