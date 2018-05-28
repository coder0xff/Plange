// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OP_ASSIGNMENT_HPP
#define INCLUDED_OP_ASSIGNMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ADDITION_ASSIGNMENT;
struct ADD_SUB_ASSIGNMENT;
struct AND_ASSIGNMENT;
struct BIT_AND_ASSIGNMENT;
struct BIT_NOT_ASSIGNMENT;
struct BIT_OR_ASSIGNMENT;
struct BIT_XOR_ASSIGNMENT;
struct COMPOSITION_ASSIGNMENT;
struct COMPOUND_ASSIGNMENT;
struct CROSS_PRODUCT_ASSIGNMENT;
struct DIVISION_ASSIGNMENT;
struct EXPONENTIATION_ASSIGNMENT;
struct FACTORIAL_ASSIGNMENT;
struct IMPLICATION_ASSIGNMENT;
struct INTEGER_DIVISION_ASSIGNMENT;
struct INTERSECTION_ASSIGNMENT;
struct MODULATION_ASSIGNMENT;
struct MULTIPLICATION_ASSIGNMENT;
struct NAND_ASSIGNMENT;
struct NEGATION_ASSIGNMENT;
struct NOR_ASSIGNMENT;
struct NOT_ASSIGNMENT;
struct NULL_COALESCE_ASSIGNMENT;
struct OR_ASSIGNMENT;
struct POST_DEC;
struct POST_INC;
struct PREPEND_ASSIGNMENT;
struct PRE_DEC;
struct PRE_INC;
struct RADICAL_ASSIGNMENT;
struct SHIFTL_ASSIGNMENT;
struct SHIFTR_ASSIGNMENT;
struct SUBTRACTION_ASSIGNMENT;
struct SYMMETRIC_DIFFERENCE_ASSIGNMENT;
struct UNION_ASSIGNMENT;
struct XOR_ASSIGNMENT;

typedef std::variant<
	erased<ADD_SUB_ASSIGNMENT>,
	erased<ADDITION_ASSIGNMENT>,
	erased<AND_ASSIGNMENT>,
	erased<BIT_AND_ASSIGNMENT>,
	erased<BIT_NOT_ASSIGNMENT>,
	erased<BIT_OR_ASSIGNMENT>,
	erased<BIT_XOR_ASSIGNMENT>,
	erased<COMPOUND_ASSIGNMENT>,
	erased<COMPOSITION_ASSIGNMENT>,
	erased<CROSS_PRODUCT_ASSIGNMENT>,
	erased<DIVISION_ASSIGNMENT>,
	erased<EXPONENTIATION_ASSIGNMENT>,
	erased<FACTORIAL_ASSIGNMENT>,
	erased<IMPLICATION_ASSIGNMENT>,
	erased<INTEGER_DIVISION_ASSIGNMENT>,
	erased<INTERSECTION_ASSIGNMENT>,
	erased<MODULATION_ASSIGNMENT>,
	erased<MULTIPLICATION_ASSIGNMENT>,
	erased<NAND_ASSIGNMENT>,
	erased<NEGATION_ASSIGNMENT>,
	erased<NOR_ASSIGNMENT>,
	erased<NOT_ASSIGNMENT>,
	erased<NULL_COALESCE_ASSIGNMENT>,
	erased<OR_ASSIGNMENT>,
	erased<PRE_DEC>,
	erased<PRE_INC>,
	erased<PREPEND_ASSIGNMENT>,
	erased<POST_DEC>,
	erased<POST_INC>,
	erased<RADICAL_ASSIGNMENT>,
	erased<SHIFTL_ASSIGNMENT>,
	erased<SHIFTR_ASSIGNMENT>,
	erased<SUBTRACTION_ASSIGNMENT>,
	erased<SYMMETRIC_DIFFERENCE_ASSIGNMENT>,
	erased<UNION_ASSIGNMENT>,
	erased<XOR_ASSIGNMENT>
> OP_ASSIGNMENT_base;

struct OP_ASSIGNMENT: OP_ASSIGNMENT_base {
	static OP_ASSIGNMENT build(parlex::detail::ast_node const & n);
	explicit OP_ASSIGNMENT(OP_ASSIGNMENT_base const & value) : OP_ASSIGNMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_OP_ASSIGNMENT_HPP
