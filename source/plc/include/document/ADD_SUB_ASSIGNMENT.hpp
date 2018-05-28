// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ADD_SUB_ASSIGNMENT_HPP
#define INCLUDED_ADD_SUB_ASSIGNMENT_HPP

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

struct ADD_SUB_ASSIGNMENT {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC20xB1_t>,
		parlex::detail::document::text<literal_0x2B0x2D_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<erased<IC>> field_5;
	
	erased<EXPRESSION> field_6;
	


	explicit ADD_SUB_ASSIGNMENT(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			parlex::detail::document::text<literal_0xC20xB1_t>,
			parlex::detail::document::text<literal_0x2B0x2D_t>
		> && field_3, std::variant<
			parlex::detail::document::text<literal_0x3C0x2D_t>,
			parlex::detail::document::text<literal_0xE20x860x90_t>
		> && field_4, std::vector<erased<IC>> && field_5, erased<EXPRESSION> && field_6) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}

	ADD_SUB_ASSIGNMENT(ADD_SUB_ASSIGNMENT const & other) = default;
	ADD_SUB_ASSIGNMENT(ADD_SUB_ASSIGNMENT && move) = default;

	static ADD_SUB_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ADD_SUB_ASSIGNMENT_HPP
