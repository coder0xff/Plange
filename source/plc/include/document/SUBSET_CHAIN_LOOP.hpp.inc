// This file was generated using parlex's cpp_generator

struct SUBSET_CHAIN_LOOP {
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>,
		std::std::integral_constant<int, 2>,
		std::std::integral_constant<int, 3>,
		std::std::integral_constant<int, 4>
	> field_1;
	std::vector<IC> field_2;
	EXPRESSION field_3;
	std::optional<std::tuple<
		std::vector<IC>,
		SUBSET_CHAIN_LOOP
	>> field_4;
};

