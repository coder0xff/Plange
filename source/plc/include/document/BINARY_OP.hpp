// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_OP_HPP
#define INCLUDED_BINARY_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct BINARY_ARITHMETIC_OP;
struct BINARY_COLLECTION_OP;
struct BINARY_LOGICAL_OP;
struct BITWISE_OP;
struct CONSTRUCTIVE_OP;
struct RELATIONAL_OP;

typedef std::variant<
	erased<BINARY_ARITHMETIC_OP>,
	erased<BINARY_COLLECTION_OP>,
	erased<BINARY_LOGICAL_OP>,
	erased<BITWISE_OP>,
	erased<CONSTRUCTIVE_OP>,
	erased<RELATIONAL_OP>
> BINARY_OP_base;

struct BINARY_OP: BINARY_OP_base {
	static std::optional<BINARY_OP> build(std::vector<parlex::details::match>::iterator & i);
	explicit BINARY_OP(BINARY_OP_base const & value) : BINARY_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BINARY_OP_HPP
