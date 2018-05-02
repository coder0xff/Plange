// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NEGATION_HPP
#define INCLUDED_NEGATION_HPP

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

struct NEGATION {
	parlex::detail::document::text<literal_0x2D_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit NEGATION(
		parlex::detail::document::text<literal_0x2D_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	NEGATION(NEGATION const & other) = default;
	NEGATION(NEGATION && move) = default;

	static NEGATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_NEGATION_HPP
