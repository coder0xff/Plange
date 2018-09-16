// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NEAREST_INTEGER_HPP
#define INCLUDED_NEAREST_INTEGER_HPP

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

struct NEAREST_INTEGER1_t {
	parlex::detail::document::text<literal_0xE20x8C0x8A_t> dont_care0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0xE20x8C0x89_t> dont_care4;
	


	explicit NEAREST_INTEGER1_t
		(parlex::detail::document::text<literal_0xE20x8C0x8A_t> && dont_care0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0xE20x8C0x89_t> && dont_care4)
		: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dont_care4(std::move(dont_care4)) {}

	NEAREST_INTEGER1_t(NEAREST_INTEGER1_t const & other) = default;
	NEAREST_INTEGER1_t(NEAREST_INTEGER1_t && move) = default;

	static NEAREST_INTEGER1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct NEAREST_INTEGER2_t {
	parlex::detail::document::text<literal_0x7C__t> dont_care0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0x270x7C_t> dont_care4;
	


	explicit NEAREST_INTEGER2_t
		(parlex::detail::document::text<literal_0x7C__t> && dont_care0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x270x7C_t> && dont_care4)
		: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dont_care4(std::move(dont_care4)) {}

	NEAREST_INTEGER2_t(NEAREST_INTEGER2_t const & other) = default;
	NEAREST_INTEGER2_t(NEAREST_INTEGER2_t && move) = default;

	static NEAREST_INTEGER2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	NEAREST_INTEGER1_t,
	NEAREST_INTEGER2_t
> NEAREST_INTEGER_base;

struct NEAREST_INTEGER: NEAREST_INTEGER_base {
	static NEAREST_INTEGER build(parlex::detail::ast_node const & n);
	explicit NEAREST_INTEGER(NEAREST_INTEGER_base const & value) : NEAREST_INTEGER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_NEAREST_INTEGER_HPP
