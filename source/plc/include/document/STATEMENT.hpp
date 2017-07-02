// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_HPP
#define INCLUDED_STATEMENT_HPP
struct STATEMENT {
	std::variant<
		ASSIGNMENT_CHAIN,
		BREAK,
		CONTINUE,
		DEFINITION,
		DO,
		EXPRESSION,
		FOR,
		FOR_COLLECTION,
		FREE,
		IMPORT,
		LOCK,
		LOOP,
		READ_LOCK,
		RETURN,
		THROW,
		TRY,
		TYPE_CONSTRAINT,
		WRITE_LOCK,
		USING
	> field_1;
	std::vector<IC> field_2;
};

#endif //INCLUDED_STATEMENT_HPP