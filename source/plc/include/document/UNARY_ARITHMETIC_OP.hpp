// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_ARITHMETIC_OP_HPP
#define INCLUDED_UNARY_ARITHMETIC_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

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
> UNARY_ARITHMETIC_OP_base;

struct UNARY_ARITHMETIC_OP: UNARY_ARITHMETIC_OP_base {
	static std::optional<UNARY_ARITHMETIC_OP> build(std::vector<parlex::details::match>::iterator & i);
	explicit UNARY_ARITHMETIC_OP(UNARY_ARITHMETIC_OP_base const & value) : UNARY_ARITHMETIC_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_UNARY_ARITHMETIC_OP_HPP
