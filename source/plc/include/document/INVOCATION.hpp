// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INVOCATION_HPP
#define INCLUDED_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY_INVOCATION;
struct PARENTHETICAL_INVOCATION;
struct TYPE_INVOCATION;

typedef std::variant<
	erased<PARENTHETICAL_INVOCATION>,
	erased<ARRAY_INVOCATION>,
	erased<TYPE_INVOCATION>
> INVOCATION_base;

struct INVOCATION: INVOCATION_base {
	static INVOCATION build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit INVOCATION(INVOCATION_base const & value) : INVOCATION_base(value) {}
};
} // namespace plc



#endif //INCLUDED_INVOCATION_HPP
