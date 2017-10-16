// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_KLEENE_STAR_HPP
#define INCLUDED_KLEENE_STAR_HPP

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

struct KLEENE_STAR {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	


	explicit KLEENE_STAR(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	KLEENE_STAR(KLEENE_STAR const & other) = default;
	KLEENE_STAR(KLEENE_STAR && move) = default;

	static KLEENE_STAR build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_KLEENE_STAR_HPP
