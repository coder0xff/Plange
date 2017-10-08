// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSION_HPP
#define INCLUDED_DIMENSION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSIONAL_ANALYSIS_OP;
struct IDENTIFIER;

typedef std::variant<
	erased<IDENTIFIER>,
	erased<DIMENSIONAL_ANALYSIS_OP>
> DIMENSION_base;

struct DIMENSION: DIMENSION_base {
	static DIMENSION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit DIMENSION(DIMENSION_base const & value) : DIMENSION_base(value) {}
};
} // namespace plc



#endif //INCLUDED_DIMENSION_HPP
