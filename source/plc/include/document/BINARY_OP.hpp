// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_OP_HPP
#define INCLUDED_BINARY_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BINARY_ARITHMETIC_OP;
struct BINARY_COLLECTION_OP;
struct BINARY_LOGICAL_OP;
struct BITWISE_OP;
struct CONSTRUCTIVE_OP;
struct RELATIONAL_OP;

typedef std::variant<
	val<BINARY_ARITHMETIC_OP>,
	val<BINARY_COLLECTION_OP>,
	val<BINARY_LOGICAL_OP>,
	val<BITWISE_OP>,
	val<CONSTRUCTIVE_OP>,
	val<RELATIONAL_OP>
> BINARY_OP_base;

struct BINARY_OP: BINARY_OP_base {
	static BINARY_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_OP(BINARY_OP_base const & value) : BINARY_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_BINARY_OP_HPP
