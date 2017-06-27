// This file was generated using parlex's cpp_generator

struct IDENTIFIER {
	std::variant<
		letter,
		std::std::integral_constant<int, 1>
	> field_1;
	std::vector<std::variant<
		letter,
		number,
		std::std::integral_constant<int, 2>
	>> field_2;
};

