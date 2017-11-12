// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MULTIPLICATIVE_OP_HPP
#define INCLUDED_MULTIPLICATIVE_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct CROSS_PRODUCT;
struct DOT_PRODUCT;
struct MULTIPLICATION;

typedef std::variant<
	erased<CROSS_PRODUCT>,
	erased<DOT_PRODUCT>,
	erased<MULTIPLICATION>
> MULTIPLICATIVE_OP_base;

struct MULTIPLICATIVE_OP: MULTIPLICATIVE_OP_base {
	static MULTIPLICATIVE_OP build(parlex::details::ast_node const & n);
	explicit MULTIPLICATIVE_OP(MULTIPLICATIVE_OP_base const & value) : MULTIPLICATIVE_OP_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_MULTIPLICATIVE_OP_HPP
