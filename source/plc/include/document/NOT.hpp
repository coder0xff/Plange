// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NOT_HPP
#define INCLUDED_NOT_HPP

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

struct NOT {
	std::variant<
		literal_0xC20xAC_t,
		literal_0x7E_t
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	


	explicit NOT(
		std::variant<
			literal_0xC20xAC_t,
			literal_0x7E_t
		> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	NOT(NOT const & other) = default;
	NOT(NOT && move) = default;

	static NOT build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_NOT_HPP
