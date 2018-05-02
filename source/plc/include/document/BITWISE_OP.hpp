// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BITWISE_OP_HPP
#define INCLUDED_BITWISE_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BIT_AND;
struct BIT_OR;
struct BIT_XOR;

typedef std::variant<
	erased<BIT_AND>,
	erased<BIT_OR>,
	erased<BIT_XOR>
> BITWISE_OP_base;

struct BITWISE_OP: BITWISE_OP_base {
	static BITWISE_OP build(parlex::detail::ast_node const & n);
	explicit BITWISE_OP(BITWISE_OP_base const & value) : BITWISE_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_BITWISE_OP_HPP
