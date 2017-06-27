// This file was generated using parlex's cpp_generator

struct TYPE_INVOCATION {
	EXPRESSION field_1;
	std::tuple<
		std::optional<std::tuple<
			std::vector<IC>,
			std::variant<
				ARGUMENT,
				ARGUMENT_PACK
			>
		>>,
		std::vector<std::tuple<
			std::vector<IC>,
			std::optional<std::tuple<
				std::vector<IC>,
				std::variant<
					ARGUMENT,
					ARGUMENT_PACK
				>
			>>
		>>,
		std::vector<IC>
	> field_2;
};

