// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IC_HPP
#define INCLUDED_IC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct COMMENT;
struct EMBEDDED_COMMENT;
struct END_OF_LINE_COMMENT;
struct WS;

typedef std::variant<
	erased<COMMENT>,
	erased<EMBEDDED_COMMENT>,
	erased<END_OF_LINE_COMMENT>,
	erased<WS>
> IC_base;

struct IC: IC_base {
	static IC build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit IC(IC_base const & value) : IC_base(value) {}
};
} // namespace plc



#endif //INCLUDED_IC_HPP
