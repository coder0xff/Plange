// This file was generated using parlex's cpp_generator

struct IF {
	PARENTHETICAL condition;
	std::vector<IC> field_1;
	std::vector<IC> field_2;
	std::vector<std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		PARENTHETICAL,
		std::vector<IC>,
		EXPRESSION
	>> field_3;
	std::optional<std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		EXPRESSION
	>> field_4;
	EXPRESSION invoke;
};

