// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_USING_HPP
#define INCLUDED_USING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BLOCK;
struct EXPRESSION;
struct IC;

struct USING {
	std::vector<erased<IC>> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	std::vector<erased<IC>> field_5;
	
	erased<BLOCK> field_6;
	


	explicit USING(
		std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, std::vector<erased<IC>> && field_5, erased<BLOCK> && field_6) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}

	USING(USING const & other) = default;
	USING(USING && move) = default;

	static USING build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_USING_HPP
