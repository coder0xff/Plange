// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_SCOPE_HPP
#define INCLUDED_STATEMENT_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct STATEMENT;

typedef std::vector<std::variant<
	erased<IC>,
	erased<STATEMENT>
>> STATEMENT_SCOPE_base;

struct STATEMENT_SCOPE: STATEMENT_SCOPE_base {
	static STATEMENT_SCOPE build(parlex::detail::ast_node const & n);
	explicit STATEMENT_SCOPE(STATEMENT_SCOPE_base const & value) : STATEMENT_SCOPE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_STATEMENT_SCOPE_HPP
