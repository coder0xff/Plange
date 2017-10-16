// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXPONENTIATION_HPP
#define INCLUDED_EXPONENTIATION_HPP

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

struct EXPONENTIATION {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::vector<erased<IC>> field_3;
	
	erased<EXPRESSION> field_4;
	


	explicit EXPONENTIATION(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	EXPONENTIATION(EXPONENTIATION const & other) = default;
	EXPONENTIATION(EXPONENTIATION && move) = default;

	static EXPONENTIATION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EXPONENTIATION_HPP
