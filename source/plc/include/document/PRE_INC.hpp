// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PRE_INC_HPP
#define INCLUDED_PRE_INC_HPP

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

struct PRE_INC {
	parlex::details::document::text<literal_0x2B0x2B_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	


	explicit PRE_INC(
		parlex::details::document::text<literal_0x2B0x2B_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PRE_INC(PRE_INC const & other) = default;
	PRE_INC(PRE_INC && move) = default;

	static PRE_INC build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_PRE_INC_HPP
