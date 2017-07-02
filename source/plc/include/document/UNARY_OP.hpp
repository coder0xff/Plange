// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_OP_HPP
#define INCLUDED_UNARY_OP_HPP

struct ALLOCATION;
struct CARDINALITY;
struct KLEENE_STAR;
struct UNARY_ARITHMETIC_OP;
struct UNARY_LOGICAL_OP;

typedef std::variant<
	erased<ALLOCATION>,
	erased<CARDINALITY>,
	erased<KLEENE_STAR>,
	erased<UNARY_ARITHMETIC_OP>,
	erased<UNARY_LOGICAL_OP>
> UNARY_OP;

#endif //INCLUDED_UNARY_OP_HPP
