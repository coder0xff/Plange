// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IC_HPP
#define INCLUDED_IC_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct COMMENT;
struct EMBEDDED_COMMENT;
struct END_OF_LINE_COMMENT;
struct WS;

typedef std::variant<
	val<COMMENT>,
	val<EMBEDDED_COMMENT>,
	val<END_OF_LINE_COMMENT>,
	val<WS>
> IC_base;

struct IC: IC_base {
	static IC build(parlex::detail::ast_node const & n);
	explicit IC(IC_base const & value) : IC_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_IC_HPP
