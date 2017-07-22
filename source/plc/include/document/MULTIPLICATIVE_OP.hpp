// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MULTIPLICATIVE_OP_HPP
#define INCLUDED_MULTIPLICATIVE_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct CROSS_PRODUCT;
struct DOT_PRODUCT;
struct MULTIPLICATION;

typedef std::variant<
	erased<CROSS_PRODUCT>,
	erased<DOT_PRODUCT>,
	erased<MULTIPLICATION>
> MULTIPLICATIVE_OP;

#endif //INCLUDED_MULTIPLICATIVE_OP_HPP
