// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_HPP
#define INCLUDED_PARAMETER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct PARAMETER_ANALYTIC;
struct PARAMETER_NATURAL;

typedef std::variant<
	erased<PARAMETER_NATURAL>,
	erased<PARAMETER_ANALYTIC>
> PARAMETER_base;

struct PARAMETER: PARAMETER_base {
	static PARAMETER build(parlex::detail::ast_node const & n);
	explicit PARAMETER(PARAMETER_base const & value) : PARAMETER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_PARAMETER_HPP
