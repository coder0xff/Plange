// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_LOGICAL_OP_HPP
#define INCLUDED_UNARY_LOGICAL_OP_HPP

struct ALL;
struct EXISTS;
struct EXISTS_ONE;
struct NOT;

typedef std::variant<
	erased<ALL>,
	erased<EXISTS>,
	erased<EXISTS_ONE>,
	erased<NOT>
> UNARY_LOGICAL_OP;

#endif //INCLUDED_UNARY_LOGICAL_OP_HPP
