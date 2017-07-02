// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RELATIONAL_OP_HPP
#define INCLUDED_RELATIONAL_OP_HPP

struct CASTS;
struct DOWNCASTS;
struct EXACTLY;
struct IMPLEMENTS;
struct INEQUALITY;
struct INHERITS;
struct IS;
struct RELATIONAL_COLLECTION_OP;
struct UPCASTS;

typedef std::variant<
	erased<CASTS>,
	erased<DOWNCASTS>,
	erased<EXACTLY>,
	erased<IMPLEMENTS>,
	erased<INEQUALITY>,
	erased<INHERITS>,
	erased<IS>,
	erased<RELATIONAL_COLLECTION_OP>,
	erased<UPCASTS>
> RELATIONAL_OP;

#endif //INCLUDED_RELATIONAL_OP_HPP
