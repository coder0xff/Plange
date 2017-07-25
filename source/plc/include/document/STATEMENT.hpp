// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_HPP
#define INCLUDED_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ASSIGNMENT_CHAIN;
struct BREAK;
struct CONTINUE;
struct DEFINITION;
struct DO;
struct EXPRESSION;
struct FOR;
struct FOR_COLLECTION;
struct FREE;
struct IC;
struct IMPORT;
struct LOCK;
struct LOOP;
struct READ_LOCK;
struct RETURN;
struct THROW;
struct TRY;
struct TYPE_CONSTRAINT;
struct USING;
struct WRITE_LOCK;

struct STATEMENT {
	std::variant<
		erased<ASSIGNMENT_CHAIN>,
		erased<BREAK>,
		erased<CONTINUE>,
		erased<DEFINITION>,
		erased<DO>,
		erased<EXPRESSION>,
		erased<FOR>,
		erased<FOR_COLLECTION>,
		erased<FREE>,
		erased<IMPORT>,
		erased<LOCK>,
		erased<LOOP>,
		erased<READ_LOCK>,
		erased<RETURN>,
		erased<THROW>,
		erased<TRY>,
		erased<TYPE_CONSTRAINT>,
		erased<WRITE_LOCK>,
		erased<USING>
	> field_1;
	std::vector<erased<IC>> field_2;

	STATEMENT(
		std::variant<
			erased<ASSIGNMENT_CHAIN>,
			erased<BREAK>,
			erased<CONTINUE>,
			erased<DEFINITION>,
			erased<DO>,
			erased<EXPRESSION>,
			erased<FOR>,
			erased<FOR_COLLECTION>,
			erased<FREE>,
			erased<IMPORT>,
			erased<LOCK>,
			erased<LOOP>,
			erased<READ_LOCK>,
			erased<RETURN>,
			erased<THROW>,
			erased<TRY>,
			erased<TYPE_CONSTRAINT>,
			erased<WRITE_LOCK>,
			erased<USING>
		> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_STATEMENT_HPP
