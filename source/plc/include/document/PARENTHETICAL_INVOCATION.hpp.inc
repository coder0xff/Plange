// This file was generated using parlex's cpp_generator

struct PARENTHETICAL_INVOCATION {
	EXPRESSION field_1;
	std::vector<IC> field_2;
	std::optional<std::tuple<
		std::vector<IC>,
		std::variant<
			ARGUMENT,
			ARGUMENT_PACK
		>
	>> field_3;
	std::vector<std::tuple<
		std::vector<IC>,
		std::optional<std::tuple<
			std::vector<IC>,
			std::variant<
				ARGUMENT,
				ARGUMENT_PACK
			>
		>>
	>> field_4;
	std::vector<IC> field_5;
};

