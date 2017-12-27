// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_ACCESS_HPP
#define INCLUDED_MEMBER_ACCESS_HPP

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
struct IDENTIFIER;

struct MEMBER_ACCESS {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2E_t> dontCare2;
	
	std::vector<erased<IC>> field_3;
	
	erased<IDENTIFIER> field_4;
	


	explicit MEMBER_ACCESS(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0x2E_t> && dontCare2, std::vector<erased<IC>> && field_3, erased<IDENTIFIER> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	MEMBER_ACCESS(MEMBER_ACCESS const & other) = default;
	MEMBER_ACCESS(MEMBER_ACCESS && move) = default;

	static MEMBER_ACCESS build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_MEMBER_ACCESS_HPP
