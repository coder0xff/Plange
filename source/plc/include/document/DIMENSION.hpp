// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSION_HPP
#define INCLUDED_DIMENSION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSIONAL_ANALYSIS_OP;
struct IDENTIFIER;

typedef std::variant<
	erased<IDENTIFIER>,
	erased<DIMENSIONAL_ANALYSIS_OP>
> DIMENSION_base;

struct DIMENSION: DIMENSION_base {
	static DIMENSION build(parlex::detail::ast_node const & n);
	explicit DIMENSION(DIMENSION_base const & value) : DIMENSION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_DIMENSION_HPP
