// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_LOGICAL_OP_HPP
#define INCLUDED_BINARY_LOGICAL_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct AND;
struct IFF;
struct IMPLICATION;
struct MAPS_TO;
struct NAND;
struct NOR;
struct OR;
struct XOR;

typedef std::variant<
	val<AND>,
	val<IFF>,
	val<IMPLICATION>,
	val<MAPS_TO>,
	val<NAND>,
	val<NOR>,
	val<OR>,
	val<XOR>
> BINARY_LOGICAL_OP_base;

struct BINARY_LOGICAL_OP: BINARY_LOGICAL_OP_base {
	static BINARY_LOGICAL_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_LOGICAL_OP(BINARY_LOGICAL_OP_base const & value) : BINARY_LOGICAL_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_BINARY_LOGICAL_OP_HPP
