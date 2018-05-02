// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CARDINALITY_HPP
#define INCLUDED_CARDINALITY_HPP

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

struct CARDINALITY {
	parlex::detail::document::text<literal_0x23_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit CARDINALITY(
		parlex::detail::document::text<literal_0x23_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	CARDINALITY(CARDINALITY const & other) = default;
	CARDINALITY(CARDINALITY && move) = default;

	static CARDINALITY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CARDINALITY_HPP
