// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSIONAL_NUMBER_HPP
#define INCLUDED_DIMENSIONAL_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSION;
struct NON_NEG_NUMBER;

struct DIMENSIONAL_NUMBER {
	erased<NON_NEG_NUMBER> field_1;
	
	erased<DIMENSION> field_2;
	


	explicit DIMENSIONAL_NUMBER(
		erased<NON_NEG_NUMBER> && field_1, erased<DIMENSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	DIMENSIONAL_NUMBER(DIMENSIONAL_NUMBER const & other) = default;
	DIMENSIONAL_NUMBER(DIMENSIONAL_NUMBER && move) = default;

	static DIMENSIONAL_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DIMENSIONAL_NUMBER_HPP
