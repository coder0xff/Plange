// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_ARITHMETIC_OP_HPP
#define INCLUDED_UNARY_ARITHMETIC_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct FACTORIAL;
struct NEGATION;
struct POST_DEC;
struct POST_INC;
struct PRE_DEC;
struct PRE_INC;
struct RADICAL;

typedef std::variant<
	erased<FACTORIAL>,
	erased<NEGATION>,
	erased<POST_DEC>,
	erased<POST_INC>,
	erased<PRE_DEC>,
	erased<PRE_INC>,
	erased<RADICAL>
> UNARY_ARITHMETIC_OP;

#endif //INCLUDED_UNARY_ARITHMETIC_OP_HPP
