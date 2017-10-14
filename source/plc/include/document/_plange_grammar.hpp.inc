// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLANGE_GRAMMAR_HPP
#define INCLUDED_PLANGE_GRAMMAR_HPP

#include "parlex/builder.hpp"
#include "parlex/details/grammar.hpp"

#include "_plange_literals.hpp"
namespace plc {

class plange_grammar : public parlex::details::grammar {
public:
	static plange_grammar const & get() {
		static plange_grammar value;
		return value;
	}

	production const & ADDITION;
	production const & ADD_SUB;
	production const & ALL;
	production const & ALLOCATION;
	production const & AND;
	production const & ARGUMENT;
	production const & ARGUMENT_PACK;
	production const & ARRAY;
	production const & ARRAY_INDEXER;
	production const & ARRAY_INVOCATION;
	production const & ASM_EXPRESSION;
	production const & ASM_FUNCTION;
	production const & ASM_IDENTIFIER;
	production const & ASM_OP;
	production const & ASM_PTR_ARITHMETIC_ATT;
	production const & ASM_PTR_ARITHMETIC_ATT_REG;
	production const & ASM_PTR_ARITHMETIC_INTEL;
	production const & ASM_SCOPE;
	production const & ASM_STATEMENT;
	production const & ASSIGNMENT_CHAIN;
	production const & ATTRIBUTE;
	production const & BIJECTION;
	production const & BINARY_ARITHMETIC_OP;
	production const & BINARY_COLLECTION_OP;
	production const & BINARY_LOGICAL_OP;
	production const & BINARY_OP;
	production const & BITWISE_OP;
	production const & BIT_AND;
	production const & BIT_NOT;
	production const & BIT_OR;
	production const & BIT_XOR;
	production const & BLOCK;
	production const & BOOL;
	production const & BREAK;
	production const & CARDINALITY;
	production const & CAST;
	production const & CASTS;
	production const & CEILING;
	production const & COMMENT;
	production const & COMPLEMENT;
	production const & COMPOSITION;
	production const & COMPOUND;
	production const & CONDITIONAL;
	production const & CONSTRUCTIVE_OP;
	production const & CONTINUE;
	production const & CROSS_PRODUCT;
	production const & DATE;
	production const & DATE_TIME;
	production const & DATE_YEAR_DAY;
	production const & DATE_YEAR_MONTH_DAY;
	production const & DECLARATION;
	production const & DEFINITION;
	production const & DELTA;
	production const & DIMENSION;
	production const & DIMENSIONAL_ANALYSIS_OP;
	production const & DIMENSIONAL_NUMBER;
	production const & DIVISION;
	production const & DO;
	production const & DOT_PRODUCT;
	production const & DOWNCASTS;
	production const & EMBEDDED_COMMENT;
	production const & EMBEDDED_COMMENT_INTERIOR;
	production const & EMBEDDED_NEWLINE_STRING;
	production const & EMBEDDED_NEWLINE_STRING_INTERIOR;
	production const & EMBEDDED_STRING;
	production const & EMBEDDED_STRING_INTERIOR;
	production const & END_OF_LINE_COMMENT;
	production const & ENUM;
	production const & ENUM_ELEMENT;
	production const & EQUALITY_CHAIN;
	production const & EQUALITY_CHAIN_LOOP;
	production const & EXACTLY;
	production const & EXISTS;
	production const & EXISTS_ONE;
	production const & EXPONENTIATION;
	production const & EXPRESSION;
	production const & FACTORIAL;
	production const & FLOOR;
	production const & FOR;
	production const & FOR_COLLECTION;
	production const & FREE;
	production const & FUNCTION;
	production const & FUNCTION_MODIFIER_0;
	production const & FUNCTION_MODIFIER_1;
	production const & FUNCTION_MODIFIER_2;
	production const & FUNCTION_MODIFIER_3;
	production const & FUNCTION_MODIFIER_4;
	production const & FUNCTION_MODIFIER_ATOMIC;
	production const & FUNCTION_MODIFIER_CALLING_CONVENTION;
	production const & FUNCTION_MODIFIER_MODEL;
	production const & FUNCTION_MODIFIER_PLATFORM;
	production const & FUNCTION_MODIFIER_STABILITY;
	production const & FUNCTION_MODIFIER_THROWING;
	production const & GREATER_CHAIN;
	production const & GREATER_CHAIN_LOOP;
	production const & HAS;
	production const & HEX;
	production const & IC;
	production const & ICR;
	production const & IDENTIFIER;
	production const & IF;
	production const & IFF;
	production const & IMPLEMENTS;
	production const & IMPLICATION;
	production const & IMPLICIT_TYPE_DEREFERENCE;
	production const & IMPORT;
	production const & IN;
	production const & INEQUALITY;
	production const & INHERITANCE_ITEM_PREFIX;
	production const & INHERITANCE_LIST;
	production const & INHERITS;
	production const & INTEGER_DIVISION;
	production const & INTERSECTION;
	production const & INVOCATION;
	production const & IS;
	production const & KLEENE_STAR;
	production const & LESSER_CHAIN;
	production const & LESSER_CHAIN_LOOP;
	production const & LIST;
	production const & LOCK;
	production const & LOOP;
	production const & MAGNITUDE;
	production const & MAP;
	production const & MAPS_TO;
	production const & MEMBER_ACCESS;
	production const & MEMBER_OFFSET;
	production const & MODULATION;
	production const & MULTIPLICATION;
	production const & MULTIPLICATIVE_OP;
	production const & NAND;
	production const & NEAREST_INTEGER;
	production const & NEGATION;
	production const & NON_FRACTIONAL;
	production const & NON_NEG_FRACTIONAL;
	production const & NON_NEG_INTEGER;
	production const & NON_NEG_NON_FRACTIONAL;
	production const & NON_NEG_NUMBER;
	production const & NON_ZERO_DECIMAL_DIGIT;
	production const & NOR;
	production const & NOT;
	production const & NOT_HAS;
	production const & NOT_IN;
	production const & NULL_COALESCE;
	production const & OBJECT;
	production const & OCTAL;
	production const & OR;
	production const & PARAMETER;
	production const & PARAMETER_ANALYTIC;
	production const & PARAMETER_NATURAL;
	production const & PARENTHETICAL;
	production const & PARENTHETICAL_INVOCATION;
	production const & PAYLOAD;
	production const & PLATFORM;
	production const & POST_DEC;
	production const & POST_INC;
	production const & PREPEND;
	production const & PRE_DEC;
	production const & PRE_INC;
	production const & RADICAL;
	production const & RANGE;
	production const & READ_LOCK;
	production const & RECORD;
	production const & REGEX;
	production const & RELATIONAL_COLLECTION_OP;
	production const & RELATIONAL_OP;
	production const & RETURN;
	production const & SET;
	production const & SET_COMPREHENSION;
	production const & SHIFTL;
	production const & SHIFTR;
	production const & SLICE;
	production const & STATEMENT;
	production const & STATEMENT_SCOPE;
	production const & STRING;
	production const & SUBSET_CHAIN;
	production const & SUBSET_CHAIN_LOOP;
	production const & SUBTRACTION;
	production const & SUPERSET_CHAIN;
	production const & SUPERSET_CHAIN_LOOP;
	production const & SWIZZLE;
	production const & SYMMETRIC_DIFFERENCE;
	production const & THIS;
	production const & THIS_FUNC;
	production const & THIS_TYPE;
	production const & THROW;
	production const & TIME;
	production const & TRY;
	production const & TUPLE;
	production const & TYPE;
	production const & TYPE_CONSTRAINT;
	production const & TYPE_CONSTRAINT_CHAIN;
	production const & TYPE_CONSTRAINT_HEAD;
	production const & TYPE_DEREFERENCE;
	production const & TYPE_INVOCATION;
	production const & TYPE_SCOPE;
	production const & TYPE_SCOPE_ASSIGNMENT_CHAIN;
	production const & TYPE_SCOPE_DECLARATION;
	production const & TYPE_SCOPE_TYPE_CONSTRAINT;
	production const & TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN;
	production const & TYPE_STATEMENT;
	production const & UNARY_ARITHMETIC_OP;
	production const & UNARY_LOGICAL_OP;
	production const & UNARY_OP;
	production const & UNION;
	production const & UNIT_DIVISION;
	production const & UNIT_EXPONENTIATION;
	production const & UNIT_MULTIPLICATION;
	production const & UPCASTS;
	production const & USING;
	production const & VECTOR_NORM;
	production const & VISIBILITY_MODIFIER;
	production const & VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
	production const & VOLATILE_TYPE_DEREFERENCE;
	production const & WHOLE_NUMBER;
	production const & WRITE_LOCK;
	production const & WS;
	production const & XML_DOC_STRING;
	production const & XML_DOC_STRING_INTERIOR;
	production const & XOR;
private:
	plange_grammar();

};

} // namespace plc



#endif //INCLUDED_PLANGE_GRAMMAR_HPP
