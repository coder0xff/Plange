// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_LOGICAL_OP_HPP
#define INCLUDED_BINARY_LOGICAL_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

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
	erased<AND>,
	erased<IFF>,
	erased<IMPLICATION>,
	erased<MAPS_TO>,
	erased<NAND>,
	erased<NOR>,
	erased<OR>,
	erased<XOR>
> BINARY_LOGICAL_OP_base;

struct BINARY_LOGICAL_OP: BINARY_LOGICAL_OP_base {
	static BINARY_LOGICAL_OP build(parlex::details::ast_node const & n);
	explicit BINARY_LOGICAL_OP(BINARY_LOGICAL_OP_base const & value) : BINARY_LOGICAL_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BINARY_LOGICAL_OP_HPP
