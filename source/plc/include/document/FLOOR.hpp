// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct FLOOR1_t {
	parlex::detail::document::text<literal_0xE20x8C0x8A_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x8C0x8B_t> dont_care4;
	


	explicit FLOOR1_t
		(parlex::detail::document::text<literal_0xE20x8C0x8A_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x8C0x8B_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2), dont_care4(dont_care4) {}

	FLOOR1_t(FLOOR1_t const & other) = default;
	static FLOOR1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct FLOOR2_t {
	parlex::detail::document::text<literal_0x7C__t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal__0x7C_t> dont_care4;
	


	explicit FLOOR2_t
		(parlex::detail::document::text<literal_0x7C__t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal__0x7C_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2), dont_care4(dont_care4) {}

	FLOOR2_t(FLOOR2_t const & other) = default;
	static FLOOR2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	FLOOR1_t,
	FLOOR2_t
> FLOOR_base;

struct FLOOR: FLOOR_base {
	static FLOOR build(parlex::detail::ast_node const & n);
	explicit FLOOR(FLOOR_base const & value) : FLOOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_FLOOR_HPP
