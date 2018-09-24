// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CEILING_HPP
#define INCLUDED_CEILING_HPP

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

struct CEILING1_t {
	parlex::detail::document::text<literal_0xE20x8C0x88_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0xE20x8C0x89_t> dont_care4;
	


	explicit CEILING1_t
		(parlex::detail::document::text<literal_0xE20x8C0x88_t> && dont_care0, std::vector<val<IC>> && field_1, val<EXPRESSION> && field_2, std::vector<val<IC>> && field_3, parlex::detail::document::text<literal_0xE20x8C0x89_t> && dont_care4)
		: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dont_care4(std::move(dont_care4)) {}

	CEILING1_t(CEILING1_t const & other) = default;
	CEILING1_t(CEILING1_t && move) = default;

	static CEILING1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct CEILING2_t {
	parlex::detail::document::text<literal_0x7C0x27_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x270x7C_t> dont_care4;
	


	explicit CEILING2_t
		(parlex::detail::document::text<literal_0x7C0x27_t> && dont_care0, std::vector<val<IC>> && field_1, val<EXPRESSION> && field_2, std::vector<val<IC>> && field_3, parlex::detail::document::text<literal_0x270x7C_t> && dont_care4)
		: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dont_care4(std::move(dont_care4)) {}

	CEILING2_t(CEILING2_t const & other) = default;
	CEILING2_t(CEILING2_t && move) = default;

	static CEILING2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	CEILING1_t,
	CEILING2_t
> CEILING_base;

struct CEILING: CEILING_base {
	static CEILING build(parlex::detail::ast_node const & n);
	explicit CEILING(CEILING_base const & value) : CEILING_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_CEILING_HPP
