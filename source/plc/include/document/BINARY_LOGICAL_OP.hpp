// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_LOGICAL_OP_HPP
#define INCLUDED_BINARY_LOGICAL_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

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
> BINARY_LOGICAL_OP;

#endif //INCLUDED_BINARY_LOGICAL_OP_HPP
