// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLANGE_GRAMMAR_HPP
#define INCLUDED_PLANGE_GRAMMAR_HPP

#include "parlex/builder.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/grammar.hpp"

#include "_plange_literals.hpp"

namespace plc {

class plange_grammar : public parlex::detail::grammar {
public:
	static plange_grammar const & get() {
		static plange_grammar value;
		return value;
	}

	size_t const ADDITION;
	size_t const ADD_SUB;
	size_t const ALL;
	size_t const ALLOCATION;
	size_t const AND;
	size_t const ARGUMENT;
	size_t const ARGUMENT_PACK;
	size_t const ARRAY;
	size_t const ARRAY_INDEXER;
	size_t const ARRAY_INVOCATION;
	size_t const ASM_EXPRESSION;
	size_t const ASM_FUNCTION;
	size_t const ASM_IDENTIFIER;
	size_t const ASM_OP;
	size_t const ASM_PTR_ARITHMETIC_ATT;
	size_t const ASM_PTR_ARITHMETIC_ATT_REG;
	size_t const ASM_PTR_ARITHMETIC_INTEL;
	size_t const ASM_SCOPE;
	size_t const ASM_STATEMENT;
	size_t const ASSIGNMENT_CHAIN;
	size_t const ATTRIBUTE;
	size_t const BIJECTION;
	size_t const BINARY_ARITHMETIC_OP;
	size_t const BINARY_COLLECTION_OP;
	size_t const BINARY_LOGICAL_OP;
	size_t const BINARY_OP;
	size_t const BITWISE_OP;
	size_t const BIT_AND;
	size_t const BIT_NOT;
	size_t const BIT_OR;
	size_t const BIT_XOR;
	size_t const BLOCK;
	size_t const BOOL;
	size_t const BREAK;
	size_t const CARDINALITY;
	size_t const CAST;
	size_t const CASTS;
	size_t const CEILING;
	size_t const COMMENT;
	size_t const COMPLEMENT;
	size_t const COMPOSITION;
	size_t const COMPOUND;
	size_t const CONDITIONAL;
	size_t const CONSTRUCTIVE_OP;
	size_t const CONTINUE;
	size_t const CROSS_PRODUCT;
	size_t const DATE;
	size_t const DATE_TIME;
	size_t const DATE_YEAR_DAY;
	size_t const DATE_YEAR_MONTH_DAY;
	size_t const DECLARATION;
	size_t const DEFINITION;
	size_t const DELTA;
	size_t const DIMENSION;
	size_t const DIMENSIONAL_ANALYSIS_OP;
	size_t const DIMENSIONAL_NUMBER;
	size_t const DIVISION;
	size_t const DO;
	size_t const DOT_PRODUCT;
	size_t const DOWNCASTS;
	size_t const EMBEDDED_COMMENT;
	size_t const EMBEDDED_COMMENT_INTERIOR;
	size_t const EMBEDDED_NEWLINE_STRING;
	size_t const EMBEDDED_NEWLINE_STRING_INTERIOR;
	size_t const EMBEDDED_STRING;
	size_t const EMBEDDED_STRING_INTERIOR;
	size_t const END_OF_LINE_COMMENT;
	size_t const ENUM;
	size_t const ENUM_ELEMENT;
	size_t const EQUALITY_CHAIN;
	size_t const EQUALITY_CHAIN_LOOP;
	size_t const EXACTLY;
	size_t const EXISTS;
	size_t const EXISTS_ONE;
	size_t const EXPONENTIATION;
	size_t const EXPRESSION;
	size_t const EXTERN;
	size_t const FACTORIAL;
	size_t const FLOOR;
	size_t const FOR;
	size_t const FOR_COLLECTION;
	size_t const FREE;
	size_t const FUNCTION;
	size_t const FUNCTION_MODIFIER_0;
	size_t const FUNCTION_MODIFIER_1;
	size_t const FUNCTION_MODIFIER_2;
	size_t const FUNCTION_MODIFIER_3;
	size_t const FUNCTION_MODIFIER_4;
	size_t const FUNCTION_MODIFIER_ATOMIC;
	size_t const FUNCTION_MODIFIER_CALLING_CONVENTION;
	size_t const FUNCTION_MODIFIER_MODEL;
	size_t const FUNCTION_MODIFIER_PLATFORM;
	size_t const FUNCTION_MODIFIER_STABILITY;
	size_t const FUNCTION_MODIFIER_THROWING;
	size_t const GREATER_CHAIN;
	size_t const GREATER_CHAIN_LOOP;
	size_t const HAS;
	size_t const HEX;
	size_t const IC;
	size_t const ICR;
	size_t const IDENTIFIER;
	size_t const IF;
	size_t const IFF;
	size_t const IMPLEMENTS;
	size_t const IMPLICATION;
	size_t const IMPLICIT_TYPE_DEREFERENCE;
	size_t const IMPORT;
	size_t const IN;
	size_t const INEQUALITY;
	size_t const INHERITANCE_ITEM_PREFIX;
	size_t const INHERITANCE_LIST;
	size_t const INHERITS;
	size_t const INTEGER_DIVISION;
	size_t const INTERSECTION;
	size_t const INVOCATION;
	size_t const IS;
	size_t const KLEENE_STAR;
	size_t const LESSER_CHAIN;
	size_t const LESSER_CHAIN_LOOP;
	size_t const LIST;
	size_t const LOCK;
	size_t const LOOP;
	size_t const MAGNITUDE;
	size_t const MAP;
	size_t const MAPS_TO;
	size_t const MEMBER_ACCESS;
	size_t const MEMBER_OFFSET;
	size_t const MODULATION;
	size_t const MULTIPLICATION;
	size_t const MULTIPLICATIVE_OP;
	size_t const NAND;
	size_t const NEAREST_INTEGER;
	size_t const NEGATION;
	size_t const NON_FRACTIONAL;
	size_t const NON_NEG_FRACTIONAL;
	size_t const NON_NEG_INTEGER;
	size_t const NON_NEG_NON_FRACTIONAL;
	size_t const NON_NEG_NUMBER;
	size_t const NON_ZERO_DECIMAL_DIGIT;
	size_t const NOR;
	size_t const NOT;
	size_t const NOT_HAS;
	size_t const NOT_IN;
	size_t const NULL_COALESCE;
	size_t const OBJECT;
	size_t const OCTAL;
	size_t const OR;
	size_t const PARAMETER;
	size_t const PARAMETER_ANALYTIC;
	size_t const PARAMETER_NATURAL;
	size_t const PARENTHETICAL;
	size_t const PARENTHETICAL_INVOCATION;
	size_t const PAYLOAD;
	size_t const PLATFORM;
	size_t const POST_DEC;
	size_t const POST_INC;
	size_t const PREPEND;
	size_t const PRE_DEC;
	size_t const PRE_INC;
	size_t const RADICAL;
	size_t const RANGE;
	size_t const READ_LOCK;
	size_t const RECORD;
	size_t const REGEX;
	size_t const RELATIONAL_COLLECTION_OP;
	size_t const RELATIONAL_OP;
	size_t const RETURN;
	size_t const SET;
	size_t const SET_COMPREHENSION;
	size_t const SHIFTL;
	size_t const SHIFTR;
	size_t const SLICE;
	size_t const STATEMENT;
	size_t const STATEMENT_SCOPE;
	size_t const STATIC;
	size_t const SUBSET_CHAIN;
	size_t const SUBSET_CHAIN_LOOP;
	size_t const SUBTRACTION;
	size_t const SUPERSET_CHAIN;
	size_t const SUPERSET_CHAIN_LOOP;
	size_t const SWIZZLE;
	size_t const SYMMETRIC_DIFFERENCE;
	size_t const THIS;
	size_t const THIS_FUNC;
	size_t const THIS_TYPE;
	size_t const THROW;
	size_t const TIME;
	size_t const TRY;
	size_t const TUPLE;
	size_t const TYPE;
	size_t const TYPE_CONSTRAINT;
	size_t const TYPE_CONSTRAINT_CHAIN;
	size_t const TYPE_CONSTRAINT_HEAD;
	size_t const TYPE_DEREFERENCE;
	size_t const TYPE_INVOCATION;
	size_t const TYPE_SCOPE;
	size_t const TYPE_SCOPE_ASSIGNMENT_CHAIN;
	size_t const TYPE_SCOPE_DECLARATION;
	size_t const TYPE_SCOPE_TYPE_CONSTRAINT;
	size_t const TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN;
	size_t const TYPE_STATEMENT;
	size_t const UNARY_ARITHMETIC_OP;
	size_t const UNARY_LOGICAL_OP;
	size_t const UNARY_OP;
	size_t const UNION;
	size_t const UNIT_DIVISION;
	size_t const UNIT_EXPONENTIATION;
	size_t const UNIT_MULTIPLICATION;
	size_t const UPCASTS;
	size_t const USING;
	size_t const VECTOR_NORM;
	size_t const VISIBILITY_MODIFIER;
	size_t const VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
	size_t const VOLATILE_TYPE_DEREFERENCE;
	size_t const WHOLE_NUMBER;
	size_t const WRITE_LOCK;
	size_t const WS;
	size_t const XML_DOC_STRING;
	size_t const XML_DOC_STRING_INTERIOR;
	size_t const XOR;
private:
	plange_grammar();

};

} // namespace plc



#endif //INCLUDED_PLANGE_GRAMMAR_HPP
