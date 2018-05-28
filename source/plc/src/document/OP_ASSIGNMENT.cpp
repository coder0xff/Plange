// This file was generated using Parlex's cpp_generator

#include "OP_ASSIGNMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ADDITION_ASSIGNMENT.hpp"
#include "ADD_SUB_ASSIGNMENT.hpp"
#include "AND_ASSIGNMENT.hpp"
#include "BIT_AND_ASSIGNMENT.hpp"
#include "BIT_NOT_ASSIGNMENT.hpp"
#include "BIT_OR_ASSIGNMENT.hpp"
#include "BIT_XOR_ASSIGNMENT.hpp"
#include "COMPOSITION_ASSIGNMENT.hpp"
#include "COMPOUND_ASSIGNMENT.hpp"
#include "CROSS_PRODUCT_ASSIGNMENT.hpp"
#include "DIVISION_ASSIGNMENT.hpp"
#include "EXPONENTIATION_ASSIGNMENT.hpp"
#include "FACTORIAL_ASSIGNMENT.hpp"
#include "IMPLICATION_ASSIGNMENT.hpp"
#include "INTEGER_DIVISION_ASSIGNMENT.hpp"
#include "INTERSECTION_ASSIGNMENT.hpp"
#include "MODULATION_ASSIGNMENT.hpp"
#include "MULTIPLICATION_ASSIGNMENT.hpp"
#include "NAND_ASSIGNMENT.hpp"
#include "NEGATION_ASSIGNMENT.hpp"
#include "NOR_ASSIGNMENT.hpp"
#include "NOT_ASSIGNMENT.hpp"
#include "NULL_COALESCE_ASSIGNMENT.hpp"
#include "OR_ASSIGNMENT.hpp"
#include "POST_DEC.hpp"
#include "POST_INC.hpp"
#include "PREPEND_ASSIGNMENT.hpp"
#include "PRE_DEC.hpp"
#include "PRE_INC.hpp"
#include "RADICAL_ASSIGNMENT.hpp"
#include "SHIFTL_ASSIGNMENT.hpp"
#include "SHIFTR_ASSIGNMENT.hpp"
#include "SUBTRACTION_ASSIGNMENT.hpp"
#include "SYMMETRIC_DIFFERENCE_ASSIGNMENT.hpp"
#include "UNION_ASSIGNMENT.hpp"
#include "XOR_ASSIGNMENT.hpp"

#include "OP_ASSIGNMENT.hpp"

namespace plc {

OP_ASSIGNMENT OP_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return OP_ASSIGNMENT(parlex::detail::document::element<OP_ASSIGNMENT_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::OP_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().OP_ASSIGNMENT));
	return result;
}
