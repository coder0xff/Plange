// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MODULATION_HPP
#define INCLUDED_MODULATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct MODULATION {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> field_4;


	explicit MODULATION(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		std::vector<erased<IC>> && field_3,
		erased<EXPRESSION> && field_4
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	MODULATION(MODULATION const & other) = default;
	MODULATION(MODULATION && move) = default;

	static MODULATION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_MODULATION_HPP
