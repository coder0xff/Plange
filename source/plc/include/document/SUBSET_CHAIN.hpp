// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUBSET_CHAIN_HPP
#define INCLUDED_SUBSET_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct SUBSET_CHAIN_LOOP;

struct SUBSET_CHAIN {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<SUBSET_CHAIN_LOOP> field_3;
	


	explicit SUBSET_CHAIN(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, erased<SUBSET_CHAIN_LOOP> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	SUBSET_CHAIN(SUBSET_CHAIN const & other) = default;
	SUBSET_CHAIN(SUBSET_CHAIN && move) = default;

	static SUBSET_CHAIN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SUBSET_CHAIN_HPP
