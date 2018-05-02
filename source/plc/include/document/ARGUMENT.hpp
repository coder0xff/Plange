// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_HPP
#define INCLUDED_ARGUMENT_HPP

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

typedef erased<EXPRESSION> ARGUMENT_base;

struct ARGUMENT: ARGUMENT_base {
	static ARGUMENT build(parlex::detail::ast_node const & n);
	explicit ARGUMENT(ARGUMENT_base const & value) : ARGUMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_ARGUMENT_HPP
