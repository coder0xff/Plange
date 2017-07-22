// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BITWISE_OP_HPP
#define INCLUDED_BITWISE_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct BIT_AND;
struct BIT_OR;
struct BIT_XOR;

typedef std::variant<
	erased<BIT_AND>,
	erased<BIT_OR>,
	erased<BIT_XOR>
> BITWISE_OP;

#endif //INCLUDED_BITWISE_OP_HPP
