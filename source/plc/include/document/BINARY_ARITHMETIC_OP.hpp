// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_ARITHMETIC_OP_HPP
#define INCLUDED_BINARY_ARITHMETIC_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ADDITION;
struct ADD_SUB;
struct DIVISION;
struct EXPONENTIATION;
struct INTEGER_DIVISION;
struct MODULATION;
struct MULTIPLICATIVE_OP;
struct SHIFTL;
struct SHIFTR;
struct SUBTRACTION;

typedef std::variant<
	erased<ADD_SUB>,
	erased<ADDITION>,
	erased<DIVISION>,
	erased<EXPONENTIATION>,
	erased<INTEGER_DIVISION>,
	erased<MODULATION>,
	erased<MULTIPLICATIVE_OP>,
	erased<SHIFTL>,
	erased<SHIFTR>,
	erased<SUBTRACTION>
> BINARY_ARITHMETIC_OP_base;

struct BINARY_ARITHMETIC_OP: BINARY_ARITHMETIC_OP_base {
	static std::optional<BINARY_ARITHMETIC_OP> build(std::vector<parlex::details::match>::iterator & i);
	explicit BINARY_ARITHMETIC_OP(BINARY_ARITHMETIC_OP_base const & value) : BINARY_ARITHMETIC_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BINARY_ARITHMETIC_OP_HPP
