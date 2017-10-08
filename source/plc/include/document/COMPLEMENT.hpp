// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMPLEMENT_HPP
#define INCLUDED_COMPLEMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct COMPLEMENT {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;


	explicit COMPLEMENT(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	COMPLEMENT(COMPLEMENT const & other) = default;
	COMPLEMENT(COMPLEMENT && move) = default;

	static COMPLEMENT build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_COMPLEMENT_HPP
