// This file was generated using parlex's cpp_generator

typedef std::variant<
	std::tuple<
		std::optional<std::tuple<
			TYPE_DEREFERENCE,
			std::vector<IC>
		>>,
		IDENTIFIER,
		bool
	>,
	std::tuple<
		std::optional<std::tuple<
			std::variant<
				TYPE_DEREFERENCE,
				IMPLICIT_TYPE_DEREFERENCE
			>,
			std::vector<IC>
		>>,
		IDENTIFIER,
		bool,
		std::vector<IC>,
		std::vector<IC>,
		EXPRESSION,
		bool
	>
> PARAMETER_NATURAL;