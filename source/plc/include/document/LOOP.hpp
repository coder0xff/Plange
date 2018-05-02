// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LOOP_HPP
#define INCLUDED_LOOP_HPP

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
struct PARENTHETICAL;

struct LOOP {
	std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<PARENTHETICAL> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit LOOP(
		std::variant<
			parlex::detail::document::text<literal_while_t>,
			parlex::detail::document::text<literal_until_t>
		> && field_1, std::vector<erased<IC>> && field_2, erased<PARENTHETICAL> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	LOOP(LOOP const & other) = default;
	LOOP(LOOP && move) = default;

	static LOOP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_LOOP_HPP
