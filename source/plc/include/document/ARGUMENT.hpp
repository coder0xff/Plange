// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_HPP
#define INCLUDED_ARGUMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;

typedef erased<EXPRESSION> ARGUMENT_base;

struct ARGUMENT: ARGUMENT_base {
	static ARGUMENT build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit ARGUMENT(ARGUMENT_base const & value) : ARGUMENT_base(value) {}
};
} // namespace plc



#endif //INCLUDED_ARGUMENT_HPP
