// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RADICAL_HPP
#define INCLUDED_RADICAL_HPP

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

struct RADICAL {
	parlex::details::document::text<literal_0xE20x880x9A_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit RADICAL(
		parlex::details::document::text<literal_0xE20x880x9A_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	RADICAL(RADICAL const & other) = default;
	RADICAL(RADICAL && move) = default;

	static RADICAL build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_RADICAL_HPP
