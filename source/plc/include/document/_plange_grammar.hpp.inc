// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLANGE_GRAMMAR_HPP
#define INCLUDED_PLANGE_GRAMMAR_HPP

#include "parlex/builder.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/grammar.hpp"

#include "_plange_literals.hpp"

#include "ADDITION.hpp"
#include "ADDITION_ASSIGNMENT.hpp"
#include "ADD_SUB.hpp"
#include "ADD_SUB_ASSIGNMENT.hpp"
#include "ALL.hpp"
#include "ALLOCATION.hpp"
#include "AND.hpp"
#include "AND_ASSIGNMENT.hpp"
#include "ARGUMENT_PACK.hpp"
#include "ARRAY.hpp"
#include "ARRAY_ARGUMENTS.hpp"
#include "ARRAY_INDEXER.hpp"
#include "ARRAY_INVOCATION.hpp"
#include "ASM_EXPRESSION.hpp"
#include "ASM_FUNCTION.hpp"
#include "ASM_IDENTIFIER.hpp"
#include "ASM_OP.hpp"
#include "ASM_PTR_ARITHMETIC_ATT.hpp"
#include "ASM_PTR_ARITHMETIC_ATT_REG.hpp"
#include "ASM_PTR_ARITHMETIC_INTEL.hpp"
#include "ASM_SCOPE.hpp"
#include "ASM_STATEMENT.hpp"
#include "ASSIGNMENT.hpp"
#include "ASSIGNMENT_NODE.hpp"
#include "ATTRIBUTE.hpp"
#include "BIJECTION.hpp"
#include "BINARY_ARITHMETIC_OP.hpp"
#include "BINARY_COLLECTION_OP.hpp"
#include "BINARY_LOGICAL_OP.hpp"
#include "BINARY_OP.hpp"
#include "BITWISE_OP.hpp"
#include "BIT_AND.hpp"
#include "BIT_AND_ASSIGNMENT.hpp"
#include "BIT_NOT.hpp"
#include "BIT_NOT_ASSIGNMENT.hpp"
#include "BIT_OR.hpp"
#include "BIT_OR_ASSIGNMENT.hpp"
#include "BIT_XOR.hpp"
#include "BIT_XOR_ASSIGNMENT.hpp"
#include "BLOCK.hpp"
#include "BOOL.hpp"
#include "BREAK.hpp"
#include "CARDINALITY.hpp"
#include "CAST.hpp"
#include "CASTS.hpp"
#include "CEILING.hpp"
#include "COMMENT.hpp"
#include "COMPLEMENT.hpp"
#include "COMPOSITION.hpp"
#include "COMPOSITION_ASSIGNMENT.hpp"
#include "COMPOUND.hpp"
#include "COMPOUND_ASSIGNMENT.hpp"
#include "CONDITIONAL.hpp"
#include "CONSTRUCTIVE_OP.hpp"
#include "CONTINUE.hpp"
#include "CROSS_PRODUCT.hpp"
#include "CROSS_PRODUCT_ASSIGNMENT.hpp"
#include "DATE.hpp"
#include "DATE_TIME.hpp"
#include "DATE_YEAR_DAY.hpp"
#include "DATE_YEAR_MONTH_DAY.hpp"
#include "DEFINITION.hpp"
#include "DELTA.hpp"
#include "DIMENSION.hpp"
#include "DIMENSIONAL_ANALYSIS_OP.hpp"
#include "DIMENSIONAL_NUMBER.hpp"
#include "DIVISION.hpp"
#include "DIVISION_ASSIGNMENT.hpp"
#include "DO.hpp"
#include "DOT_PRODUCT.hpp"
#include "DOWNCASTS.hpp"
#include "EMBEDDED_COMMENT.hpp"
#include "EMBEDDED_COMMENT_INTERIOR.hpp"
#include "EMBEDDED_NEWLINE_STRING.hpp"
#include "EMBEDDED_NEWLINE_STRING_INTERIOR.hpp"
#include "EMBEDDED_STRING.hpp"
#include "EMBEDDED_STRING_INTERIOR.hpp"
#include "END_OF_LINE_COMMENT.hpp"
#include "ENUM.hpp"
#include "ENUM_ELEMENT.hpp"
#include "EQUALITY.hpp"
#include "EQUALITY_NODE.hpp"
#include "EXACTLY.hpp"
#include "EXISTS.hpp"
#include "EXISTS_ONE.hpp"
#include "EXPONENTIATION.hpp"
#include "EXPONENTIATION_ASSIGNMENT.hpp"
#include "EXPRESSION.hpp"
#include "FACTORIAL.hpp"
#include "FACTORIAL_ASSIGNMENT.hpp"
#include "FLOOR.hpp"
#include "FOR.hpp"
#include "FOR_COLLECTION.hpp"
#include "FOR_STEP.hpp"
#include "FOR_STEP_LIST.hpp"
#include "FOR_STEP_NODE.hpp"
#include "FREE.hpp"
#include "FUNCTION.hpp"
#include "FUNCTION_MODIFIER_0.hpp"
#include "FUNCTION_MODIFIER_1.hpp"
#include "FUNCTION_MODIFIER_2.hpp"
#include "FUNCTION_MODIFIER_3.hpp"
#include "FUNCTION_MODIFIER_4.hpp"
#include "FUNCTION_MODIFIER_ATOMIC.hpp"
#include "FUNCTION_MODIFIER_CALLING_CONVENTION.hpp"
#include "FUNCTION_MODIFIER_MODEL.hpp"
#include "FUNCTION_MODIFIER_PLATFORM.hpp"
#include "FUNCTION_MODIFIER_STABILITY.hpp"
#include "FUNCTION_MODIFIER_THROWING.hpp"
#include "GREATER.hpp"
#include "GREATER_NODE.hpp"
#include "HAS.hpp"
#include "HEX.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IDENTIFIER_SPECIFICATION.hpp"
#include "IF.hpp"
#include "IFF.hpp"
#include "IMPLEMENTS.hpp"
#include "IMPLICATION.hpp"
#include "IMPLICATION_ASSIGNMENT.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "IMPORT.hpp"
#include "IN.hpp"
#include "INEQUALITY.hpp"
#include "INHERITANCE_ITEM_PREFIX.hpp"
#include "INHERITANCE_LIST.hpp"
#include "INHERITS.hpp"
#include "INTEGER_DIVISION.hpp"
#include "INTEGER_DIVISION_ASSIGNMENT.hpp"
#include "INTERSECTION.hpp"
#include "INTERSECTION_ASSIGNMENT.hpp"
#include "INVOCATION.hpp"
#include "IS.hpp"
#include "KLEENE_STAR.hpp"
#include "LESSER.hpp"
#include "LESSER_NODE.hpp"
#include "LIST.hpp"
#include "LOCK.hpp"
#include "LOOP.hpp"
#include "MAGNITUDE.hpp"
#include "MAP.hpp"
#include "MAPS_TO.hpp"
#include "MEMBER_ACCESS.hpp"
#include "MEMBER_OFFSET.hpp"
#include "MODULATION.hpp"
#include "MODULATION_ASSIGNMENT.hpp"
#include "MULTIPLICATION.hpp"
#include "MULTIPLICATION_ASSIGNMENT.hpp"
#include "MULTIPLICATIVE_OP.hpp"
#include "NAND.hpp"
#include "NAND_ASSIGNMENT.hpp"
#include "NATURAL_NUMBER.hpp"
#include "NEAREST_INTEGER.hpp"
#include "NEGATION.hpp"
#include "NEGATION_ASSIGNMENT.hpp"
#include "NON_FRACTIONAL.hpp"
#include "NON_NEG_FRACTIONAL.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"
#include "NON_NEG_NUMBER.hpp"
#include "NON_ZERO_DECIMAL_DIGIT.hpp"
#include "NOR.hpp"
#include "NOR_ASSIGNMENT.hpp"
#include "NOT.hpp"
#include "NOT_ASSIGNMENT.hpp"
#include "NOT_HAS.hpp"
#include "NOT_IN.hpp"
#include "NULL_COALESCE.hpp"
#include "NULL_COALESCE_ASSIGNMENT.hpp"
#include "OBJECT.hpp"
#include "OCTAL.hpp"
#include "OP_ASSIGNMENT.hpp"
#include "OR.hpp"
#include "OR_ASSIGNMENT.hpp"
#include "PARAMETER.hpp"
#include "PARAMETER_ANALYTIC.hpp"
#include "PARAMETER_NATURAL.hpp"
#include "PARENTHETICAL.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "PAYLOAD.hpp"
#include "PLATFORM.hpp"
#include "POST_DEC.hpp"
#include "POST_INC.hpp"
#include "PREPEND.hpp"
#include "PREPEND_ASSIGNMENT.hpp"
#include "PRE_DEC.hpp"
#include "PRE_INC.hpp"
#include "RADICAL.hpp"
#include "RADICAL_ASSIGNMENT.hpp"
#include "RANGE.hpp"
#include "READ_LOCK.hpp"
#include "RECORD.hpp"
#include "REGEX.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"
#include "RELATIONAL_OP.hpp"
#include "RETURN.hpp"
#include "SET.hpp"
#include "SET_COMPREHENSION.hpp"
#include "SHIFTL.hpp"
#include "SHIFTL_ASSIGNMENT.hpp"
#include "SHIFTR.hpp"
#include "SHIFTR_ASSIGNMENT.hpp"
#include "SLICE.hpp"
#include "STANDARD_ARGUMENTS.hpp"
#include "STATEMENT.hpp"
#include "STATEMENT_SCOPE.hpp"
#include "SUBSET.hpp"
#include "SUBSET_NODE.hpp"
#include "SUBTRACTION.hpp"
#include "SUBTRACTION_ASSIGNMENT.hpp"
#include "SUPERSET.hpp"
#include "SUPERSET_NODE.hpp"
#include "SWIZZLE.hpp"
#include "SYMMETRIC_DIFFERENCE.hpp"
#include "SYMMETRIC_DIFFERENCE_ASSIGNMENT.hpp"
#include "THIS.hpp"
#include "THIS_FUNC.hpp"
#include "THIS_TYPE.hpp"
#include "THROW.hpp"
#include "TIME.hpp"
#include "TRY.hpp"
#include "TUPLE.hpp"
#include "TYPE.hpp"
#include "TYPE_CONSTRAINT.hpp"
#include "TYPE_CONSTRAINT_DECLARATION.hpp"
#include "TYPE_CONSTRAINT_ELEMENT.hpp"
#include "TYPE_CONSTRAINT_SPECIFICATION.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "TYPE_INVOCATION.hpp"
#include "TYPE_SCOPE.hpp"
#include "TYPE_SCOPE_ASSIGNMENT.hpp"
#include "TYPE_SCOPE_ASSIGNMENT_NODE.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT.hpp"
#include "TYPE_STATEMENT.hpp"
#include "UNARY_ARITHMETIC_OP.hpp"
#include "UNARY_LOGICAL_OP.hpp"
#include "UNARY_OP.hpp"
#include "UNION.hpp"
#include "UNION_ASSIGNMENT.hpp"
#include "UNIT_DIVISION.hpp"
#include "UNIT_EXPONENTIATION.hpp"
#include "UNIT_MULTIPLICATION.hpp"
#include "UPCASTS.hpp"
#include "USING.hpp"
#include "VECTOR_NORM.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "VOLATILE_IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "VOLATILE_TYPE_DEREFERENCE.hpp"
#include "WHOLE_NUMBER.hpp"
#include "WRITE_LOCK.hpp"
#include "WS.hpp"
#include "XML_DOC_STRING.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"
#include "XOR.hpp"
#include "XOR_ASSIGNMENT.hpp"
namespace plc {

class plange_grammar : public parlex::detail::grammar {
public:
	static plange_grammar const & get() {
		static plange_grammar value;
		return value;
	}

	uint16_t const ADDITION;
	uint16_t const ADDITION_ASSIGNMENT;
	uint16_t const ADD_SUB;
	uint16_t const ADD_SUB_ASSIGNMENT;
	uint16_t const ALL;
	uint16_t const ALLOCATION;
	uint16_t const AND;
	uint16_t const AND_ASSIGNMENT;
	uint16_t const ARGUMENT_PACK;
	uint16_t const ARRAY;
	uint16_t const ARRAY_ARGUMENTS;
	uint16_t const ARRAY_INDEXER;
	uint16_t const ARRAY_INVOCATION;
	uint16_t const ASM_EXPRESSION;
	uint16_t const ASM_FUNCTION;
	uint16_t const ASM_IDENTIFIER;
	uint16_t const ASM_OP;
	uint16_t const ASM_PTR_ARITHMETIC_ATT;
	uint16_t const ASM_PTR_ARITHMETIC_ATT_REG;
	uint16_t const ASM_PTR_ARITHMETIC_INTEL;
	uint16_t const ASM_SCOPE;
	uint16_t const ASM_STATEMENT;
	uint16_t const ASSIGNMENT;
	uint16_t const ASSIGNMENT_NODE;
	uint16_t const ATTRIBUTE;
	uint16_t const BIJECTION;
	uint16_t const BINARY_ARITHMETIC_OP;
	uint16_t const BINARY_COLLECTION_OP;
	uint16_t const BINARY_LOGICAL_OP;
	uint16_t const BINARY_OP;
	uint16_t const BITWISE_OP;
	uint16_t const BIT_AND;
	uint16_t const BIT_AND_ASSIGNMENT;
	uint16_t const BIT_NOT;
	uint16_t const BIT_NOT_ASSIGNMENT;
	uint16_t const BIT_OR;
	uint16_t const BIT_OR_ASSIGNMENT;
	uint16_t const BIT_XOR;
	uint16_t const BIT_XOR_ASSIGNMENT;
	uint16_t const BLOCK;
	uint16_t const BOOL;
	uint16_t const BREAK;
	uint16_t const CARDINALITY;
	uint16_t const CAST;
	uint16_t const CASTS;
	uint16_t const CEILING;
	uint16_t const COMMENT;
	uint16_t const COMPLEMENT;
	uint16_t const COMPOSITION;
	uint16_t const COMPOSITION_ASSIGNMENT;
	uint16_t const COMPOUND;
	uint16_t const COMPOUND_ASSIGNMENT;
	uint16_t const CONDITIONAL;
	uint16_t const CONSTRUCTIVE_OP;
	uint16_t const CONTINUE;
	uint16_t const CROSS_PRODUCT;
	uint16_t const CROSS_PRODUCT_ASSIGNMENT;
	uint16_t const DATE;
	uint16_t const DATE_TIME;
	uint16_t const DATE_YEAR_DAY;
	uint16_t const DATE_YEAR_MONTH_DAY;
	uint16_t const DEFINITION;
	uint16_t const DELTA;
	uint16_t const DIMENSION;
	uint16_t const DIMENSIONAL_ANALYSIS_OP;
	uint16_t const DIMENSIONAL_NUMBER;
	uint16_t const DIVISION;
	uint16_t const DIVISION_ASSIGNMENT;
	uint16_t const DO;
	uint16_t const DOT_PRODUCT;
	uint16_t const DOWNCASTS;
	uint16_t const EMBEDDED_COMMENT;
	uint16_t const EMBEDDED_COMMENT_INTERIOR;
	uint16_t const EMBEDDED_NEWLINE_STRING;
	uint16_t const EMBEDDED_NEWLINE_STRING_INTERIOR;
	uint16_t const EMBEDDED_STRING;
	uint16_t const EMBEDDED_STRING_INTERIOR;
	uint16_t const END_OF_LINE_COMMENT;
	uint16_t const ENUM;
	uint16_t const ENUM_ELEMENT;
	uint16_t const EQUALITY;
	uint16_t const EQUALITY_NODE;
	uint16_t const EXACTLY;
	uint16_t const EXISTS;
	uint16_t const EXISTS_ONE;
	uint16_t const EXPONENTIATION;
	uint16_t const EXPONENTIATION_ASSIGNMENT;
	uint16_t const EXPRESSION;
	uint16_t const FACTORIAL;
	uint16_t const FACTORIAL_ASSIGNMENT;
	uint16_t const FLOOR;
	uint16_t const FOR;
	uint16_t const FOR_COLLECTION;
	uint16_t const FOR_STEP;
	uint16_t const FOR_STEP_LIST;
	uint16_t const FOR_STEP_NODE;
	uint16_t const FREE;
	uint16_t const FUNCTION;
	uint16_t const FUNCTION_MODIFIER_0;
	uint16_t const FUNCTION_MODIFIER_1;
	uint16_t const FUNCTION_MODIFIER_2;
	uint16_t const FUNCTION_MODIFIER_3;
	uint16_t const FUNCTION_MODIFIER_4;
	uint16_t const FUNCTION_MODIFIER_ATOMIC;
	uint16_t const FUNCTION_MODIFIER_CALLING_CONVENTION;
	uint16_t const FUNCTION_MODIFIER_MODEL;
	uint16_t const FUNCTION_MODIFIER_PLATFORM;
	uint16_t const FUNCTION_MODIFIER_STABILITY;
	uint16_t const FUNCTION_MODIFIER_THROWING;
	uint16_t const GREATER;
	uint16_t const GREATER_NODE;
	uint16_t const HAS;
	uint16_t const HEX;
	uint16_t const IC;
	uint16_t const IDENTIFIER;
	uint16_t const IDENTIFIER_SPECIFICATION;
	uint16_t const IF;
	uint16_t const IFF;
	uint16_t const IMPLEMENTS;
	uint16_t const IMPLICATION;
	uint16_t const IMPLICATION_ASSIGNMENT;
	uint16_t const IMPLICIT_TYPE_DEREFERENCE;
	uint16_t const IMPORT;
	uint16_t const IN;
	uint16_t const INEQUALITY;
	uint16_t const INHERITANCE_ITEM_PREFIX;
	uint16_t const INHERITANCE_LIST;
	uint16_t const INHERITS;
	uint16_t const INTEGER_DIVISION;
	uint16_t const INTEGER_DIVISION_ASSIGNMENT;
	uint16_t const INTERSECTION;
	uint16_t const INTERSECTION_ASSIGNMENT;
	uint16_t const INVOCATION;
	uint16_t const IS;
	uint16_t const KLEENE_STAR;
	uint16_t const LESSER;
	uint16_t const LESSER_NODE;
	uint16_t const LIST;
	uint16_t const LOCK;
	uint16_t const LOOP;
	uint16_t const MAGNITUDE;
	uint16_t const MAP;
	uint16_t const MAPS_TO;
	uint16_t const MEMBER_ACCESS;
	uint16_t const MEMBER_OFFSET;
	uint16_t const MODULATION;
	uint16_t const MODULATION_ASSIGNMENT;
	uint16_t const MULTIPLICATION;
	uint16_t const MULTIPLICATION_ASSIGNMENT;
	uint16_t const MULTIPLICATIVE_OP;
	uint16_t const NAND;
	uint16_t const NAND_ASSIGNMENT;
	uint16_t const NATURAL_NUMBER;
	uint16_t const NEAREST_INTEGER;
	uint16_t const NEGATION;
	uint16_t const NEGATION_ASSIGNMENT;
	uint16_t const NON_FRACTIONAL;
	uint16_t const NON_NEG_FRACTIONAL;
	uint16_t const NON_NEG_INTEGER;
	uint16_t const NON_NEG_NON_FRACTIONAL;
	uint16_t const NON_NEG_NUMBER;
	uint16_t const NON_ZERO_DECIMAL_DIGIT;
	uint16_t const NOR;
	uint16_t const NOR_ASSIGNMENT;
	uint16_t const NOT;
	uint16_t const NOT_ASSIGNMENT;
	uint16_t const NOT_HAS;
	uint16_t const NOT_IN;
	uint16_t const NULL_COALESCE;
	uint16_t const NULL_COALESCE_ASSIGNMENT;
	uint16_t const OBJECT;
	uint16_t const OCTAL;
	uint16_t const OP_ASSIGNMENT;
	uint16_t const OR;
	uint16_t const OR_ASSIGNMENT;
	uint16_t const PARAMETER;
	uint16_t const PARAMETER_ANALYTIC;
	uint16_t const PARAMETER_NATURAL;
	uint16_t const PARENTHETICAL;
	uint16_t const PARENTHETICAL_INVOCATION;
	uint16_t const PAYLOAD;
	uint16_t const PLATFORM;
	uint16_t const POST_DEC;
	uint16_t const POST_INC;
	uint16_t const PREPEND;
	uint16_t const PREPEND_ASSIGNMENT;
	uint16_t const PRE_DEC;
	uint16_t const PRE_INC;
	uint16_t const RADICAL;
	uint16_t const RADICAL_ASSIGNMENT;
	uint16_t const RANGE;
	uint16_t const READ_LOCK;
	uint16_t const RECORD;
	uint16_t const REGEX;
	uint16_t const RELATIONAL_COLLECTION_OP;
	uint16_t const RELATIONAL_OP;
	uint16_t const RETURN;
	uint16_t const SET;
	uint16_t const SET_COMPREHENSION;
	uint16_t const SHIFTL;
	uint16_t const SHIFTL_ASSIGNMENT;
	uint16_t const SHIFTR;
	uint16_t const SHIFTR_ASSIGNMENT;
	uint16_t const SLICE;
	uint16_t const STANDARD_ARGUMENTS;
	uint16_t const STATEMENT;
	uint16_t const STATEMENT_SCOPE;
	uint16_t const SUBSET;
	uint16_t const SUBSET_NODE;
	uint16_t const SUBTRACTION;
	uint16_t const SUBTRACTION_ASSIGNMENT;
	uint16_t const SUPERSET;
	uint16_t const SUPERSET_NODE;
	uint16_t const SWIZZLE;
	uint16_t const SYMMETRIC_DIFFERENCE;
	uint16_t const SYMMETRIC_DIFFERENCE_ASSIGNMENT;
	uint16_t const THIS;
	uint16_t const THIS_FUNC;
	uint16_t const THIS_TYPE;
	uint16_t const THROW;
	uint16_t const TIME;
	uint16_t const TRY;
	uint16_t const TUPLE;
	uint16_t const TYPE;
	uint16_t const TYPE_CONSTRAINT;
	uint16_t const TYPE_CONSTRAINT_DECLARATION;
	uint16_t const TYPE_CONSTRAINT_ELEMENT;
	uint16_t const TYPE_CONSTRAINT_SPECIFICATION;
	uint16_t const TYPE_DEREFERENCE;
	uint16_t const TYPE_INVOCATION;
	uint16_t const TYPE_SCOPE;
	uint16_t const TYPE_SCOPE_ASSIGNMENT;
	uint16_t const TYPE_SCOPE_ASSIGNMENT_NODE;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT;
	uint16_t const TYPE_STATEMENT;
	uint16_t const UNARY_ARITHMETIC_OP;
	uint16_t const UNARY_LOGICAL_OP;
	uint16_t const UNARY_OP;
	uint16_t const UNION;
	uint16_t const UNION_ASSIGNMENT;
	uint16_t const UNIT_DIVISION;
	uint16_t const UNIT_EXPONENTIATION;
	uint16_t const UNIT_MULTIPLICATION;
	uint16_t const UPCASTS;
	uint16_t const USING;
	uint16_t const VECTOR_NORM;
	uint16_t const VISIBILITY_MODIFIER;
	uint16_t const VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
	uint16_t const VOLATILE_TYPE_DEREFERENCE;
	uint16_t const WHOLE_NUMBER;
	uint16_t const WRITE_LOCK;
	uint16_t const WS;
	uint16_t const XML_DOC_STRING;
	uint16_t const XML_DOC_STRING_INTERIOR;
	uint16_t const XOR;
	uint16_t const XOR_ASSIGNMENT;
private:
	plange_grammar();

};

} // namespace plc



#endif //INCLUDED_PLANGE_GRAMMAR_HPP
