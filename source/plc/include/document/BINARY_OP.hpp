// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_OP_HPP
#define INCLUDED_BINARY_OP_HPP

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
> BINARY_OP;

#endif //INCLUDED_BINARY_OP_HPP
