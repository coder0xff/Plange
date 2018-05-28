// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ADDITION_ASSIGNMENT_HPP
#define INCLUDED_ADDITION_ASSIGNMENT_HPP

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

struct ADDITION_ASSIGNMENT {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0x2B0x3C0x2D_t>,
		parlex::detail::document::text<literal_0x2B0xE20x860x90_t>,
		parlex::detail::document::text<literal_0xE20xA50x86_t>
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit ADDITION_ASSIGNMENT(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			parlex::detail::document::text<literal_0x2B0x3C0x2D_t>,
			parlex::detail::document::text<literal_0x2B0xE20x860x90_t>,
			parlex::detail::document::text<literal_0xE20xA50x86_t>
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	ADDITION_ASSIGNMENT(ADDITION_ASSIGNMENT const & other) = default;
	ADDITION_ASSIGNMENT(ADDITION_ASSIGNMENT && move) = default;

	static ADDITION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ADDITION_ASSIGNMENT_HPP
