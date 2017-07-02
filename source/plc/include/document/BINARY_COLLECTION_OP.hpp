// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_COLLECTION_OP_HPP
#define INCLUDED_BINARY_COLLECTION_OP_HPP

struct BIJECTION;
struct INTERSECTION;
struct SYMMETRIC_DIFFERENCE;
struct UNION;

typedef std::variant<
	erased<BIJECTION>,
	erased<INTERSECTION>,
	erased<SYMMETRIC_DIFFERENCE>,
	erased<UNION>
> BINARY_COLLECTION_OP;

#endif //INCLUDED_BINARY_COLLECTION_OP_HPP
