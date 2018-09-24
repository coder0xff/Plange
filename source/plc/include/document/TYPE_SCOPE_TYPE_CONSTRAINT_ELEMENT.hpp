// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DEFINITION;
struct TYPE_SCOPE_ASSIGNMENT;
struct TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION;

typedef std::variant<
	val<TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION>,
	val<TYPE_SCOPE_ASSIGNMENT>,
	val<DEFINITION>
> TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base;

struct TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT: TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base {
	static TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT build(parlex::detail::ast_node const & n);
	explicit TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT(TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base const & value) : TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_HPP
