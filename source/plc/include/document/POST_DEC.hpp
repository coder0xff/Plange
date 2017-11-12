// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_POST_DEC_HPP
#define INCLUDED_POST_DEC_HPP

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

struct POST_DEC {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::details::document::text<literal_0x2D0x2D_t> dontCare2;
	


	explicit POST_DEC(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::details::document::text<literal_0x2D0x2D_t> && dontCare2) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)) {}

	POST_DEC(POST_DEC const & other) = default;
	POST_DEC(POST_DEC && move) = default;

	static POST_DEC build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_POST_DEC_HPP
