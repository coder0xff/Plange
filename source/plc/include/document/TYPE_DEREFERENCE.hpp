// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_DEREFERENCE_HPP
#define INCLUDED_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;


	explicit TYPE_DEREFERENCE(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2,
		std::vector<erased<IC>> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	TYPE_DEREFERENCE(TYPE_DEREFERENCE const & other) = default;
	TYPE_DEREFERENCE(TYPE_DEREFERENCE && move) = default;

	static TYPE_DEREFERENCE build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_DEREFERENCE_HPP
