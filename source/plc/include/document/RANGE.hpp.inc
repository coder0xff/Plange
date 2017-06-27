// This file was generated using parlex's cpp_generator

typedef std::variant<
	std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		EXPRESSION,
		std::vector<IC>,
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>
	>,
	std::tuple<
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		std::vector<IC>,
		EXPRESSION,
		std::vector<IC>,
		std::vector<IC>
	>,
	std::tuple<
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		std::vector<IC>,
		EXPRESSION,
		std::vector<IC>,
		std::vector<IC>,
		EXPRESSION,
		std::vector<IC>,
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>
	>
> RANGE;