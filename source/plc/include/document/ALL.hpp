// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALL_HPP
#define INCLUDED_ALL_HPP

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

struct ALL {
	std::variant<
		literal_0xE20x880x80_t,
		literal_all_t
	> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	


	explicit ALL(
		std::variant<
			literal_0xE20x880x80_t,
			literal_all_t
		> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	ALL(ALL const & other) = default;
	ALL(ALL && move) = default;

	static ALL build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ALL_HPP
