// This file was generated using parlex's cpp_generator

struct TYPE_CONSTRAINT_CHAIN {
	std::variant<
		DECLARATION,
		ASSIGNMENT_CHAIN,
		DEFINITION
	> field_1;
	std::optional<std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		TYPE_CONSTRAINT_CHAIN
	>> field_2;
};

