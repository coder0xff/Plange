// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WRITE_LOCK_HPP
#define INCLUDED_WRITE_LOCK_HPP

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

struct WRITE_LOCK {
	parlex::detail::document::text<literal_write_lock_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<PARENTHETICAL> field_2;
	
	std::vector<erased<IC>> field_3;
	
	erased<EXPRESSION> field_4;
	


	explicit WRITE_LOCK(
		parlex::detail::document::text<literal_write_lock_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<PARENTHETICAL> && field_2, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && field_4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	WRITE_LOCK(WRITE_LOCK const & other) = default;
	WRITE_LOCK(WRITE_LOCK && move) = default;

	static WRITE_LOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_WRITE_LOCK_HPP
