// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP
#define INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct UNIT_DIVISION;
struct UNIT_EXPONENTIATION;
struct UNIT_MULTIPLICATION;

typedef std::variant<
	erased<UNIT_DIVISION>,
	erased<UNIT_EXPONENTIATION>,
	erased<UNIT_MULTIPLICATION>
> DIMENSIONAL_ANALYSIS_OP_base;

struct DIMENSIONAL_ANALYSIS_OP: DIMENSIONAL_ANALYSIS_OP_base {
	static DIMENSIONAL_ANALYSIS_OP build(parlex::detail::ast_node const & n);
	explicit DIMENSIONAL_ANALYSIS_OP(DIMENSIONAL_ANALYSIS_OP_base const & value) : DIMENSIONAL_ANALYSIS_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP
