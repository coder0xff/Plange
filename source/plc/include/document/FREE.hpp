// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FREE_HPP
#define INCLUDED_FREE_HPP

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

struct FREE {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit FREE(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	FREE(FREE const & other) = default;
	FREE(FREE && move) = default;

	static FREE build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FREE_HPP
