// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP
#define INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

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
	static DIMENSIONAL_ANALYSIS_OP build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit DIMENSIONAL_ANALYSIS_OP(DIMENSIONAL_ANALYSIS_OP_base const & value) : DIMENSIONAL_ANALYSIS_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP
