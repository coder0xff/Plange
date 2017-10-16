// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ATTRIBUTE_HPP
#define INCLUDED_ATTRIBUTE_HPP

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

struct ATTRIBUTE {
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	


	explicit ATTRIBUTE(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	ATTRIBUTE(ATTRIBUTE const & other) = default;
	ATTRIBUTE(ATTRIBUTE && move) = default;

	static ATTRIBUTE build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ATTRIBUTE_HPP
