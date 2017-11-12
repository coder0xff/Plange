// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLEMENTS_HPP
#define INCLUDED_IMPLEMENTS_HPP

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

struct IMPLEMENTS {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::details::document::text<literal_implements_t> dontCare2;
	
	std::vector<erased<IC>> field_3;
	
	erased<EXPRESSION> field_4;
	


	explicit IMPLEMENTS(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::details::document::text<literal_implements_t> && dontCare2, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	IMPLEMENTS(IMPLEMENTS const & other) = default;
	IMPLEMENTS(IMPLEMENTS && move) = default;

	static IMPLEMENTS build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_IMPLEMENTS_HPP
