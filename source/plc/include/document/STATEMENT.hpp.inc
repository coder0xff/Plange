// This file was generated using parlex's cpp_generator

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

