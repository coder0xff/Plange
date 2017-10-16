// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CARDINALITY_HPP
#define INCLUDED_CARDINALITY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct CARDINALITY {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit CARDINALITY(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	CARDINALITY(CARDINALITY const & other) = default;
	CARDINALITY(CARDINALITY && move) = default;

	static CARDINALITY build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CARDINALITY_HPP
