// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXISTS_HPP
#define INCLUDED_EXISTS_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct EXISTS {
	std::variant<
		literal_0xE20x880x83_t,
		literal_exists_t
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;


	EXISTS(
		std::variant<
			literal_0xE20x880x83_t,
			literal_exists_t
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}

	static EXISTS build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EXISTS_HPP
