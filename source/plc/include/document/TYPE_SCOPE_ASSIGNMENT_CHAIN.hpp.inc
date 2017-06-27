// This file was generated using parlex's cpp_generator

struct TYPE_SCOPE_ASSIGNMENT_CHAIN {
	std::optional<std::tuple<
		XML_DOC_STRING,
		std::vector<IC>
	>> field_1;
	IDENTIFIER field_2;
	std::optional<std::tuple<
		std::vector<IC>,
		MEMBER_OFFSET
	>> field_3;
	std::vector<IC> field_4;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_5;
	std::vector<IC> field_6;
	std::variant<
		EXPRESSION,
		ASSIGNMENT_CHAIN
	> field_7;
};

