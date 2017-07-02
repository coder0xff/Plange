// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_INVOCATION_HPP
#define INCLUDED_TYPE_INVOCATION_HPP
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

#endif //INCLUDED_TYPE_INVOCATION_HPP