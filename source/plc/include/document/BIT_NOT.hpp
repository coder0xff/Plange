// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BIT_NOT_HPP
#define INCLUDED_BIT_NOT_HPP

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

struct BIT_NOT {
	parlex::detail::document::text<literal_0x7E0x7E_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit BIT_NOT(
		parlex::detail::document::text<literal_0x7E0x7E_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	BIT_NOT(BIT_NOT const & other) = default;
	BIT_NOT(BIT_NOT && move) = default;

	static BIT_NOT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_BIT_NOT_HPP
