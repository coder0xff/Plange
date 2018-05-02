// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXISTS_ONE_HPP
#define INCLUDED_EXISTS_ONE_HPP

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

struct EXISTS_ONE {
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x830x21_t>,
		parlex::detail::document::text<literal_exists0x21_t>
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	


	explicit EXISTS_ONE(
		std::variant<
			parlex::detail::document::text<literal_0xE20x880x830x21_t>,
			parlex::detail::document::text<literal_exists0x21_t>
		> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	EXISTS_ONE(EXISTS_ONE const & other) = default;
	EXISTS_ONE(EXISTS_ONE && move) = default;

	static EXISTS_ONE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EXISTS_ONE_HPP
