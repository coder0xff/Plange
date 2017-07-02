// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_HPP
#define INCLUDED_FOR_HPP
struct FOR {
	EXPRESSION condition;
	std::vector<IC> field_1;
	std::vector<IC> field_2;
	std::vector<IC> field_3;
	std::vector<IC> field_4;
	std::vector<IC> field_5;
	EXPRESSION field_6;
	std::optional<std::tuple<
		STATEMENT_SCOPE,
		std::vector<IC>
	>> initializer;
	std::optional<std::tuple<
		ASSIGNMENT_CHAIN,
		std::vector<std::tuple<
			std::vector<IC>,
			std::vector<IC>,
			ASSIGNMENT_CHAIN
		>>,
		std::vector<IC>
	>> step;
};

#endif //INCLUDED_FOR_HPP