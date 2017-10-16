// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BITWISE_OP_HPP
#define INCLUDED_BITWISE_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

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
	static BITWISE_OP build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit BITWISE_OP(BITWISE_OP_base const & value) : BITWISE_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BITWISE_OP_HPP
