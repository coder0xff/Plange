// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
struct TYPE_CONSTRAINT_CHAIN {
	std::variant<
		DECLARATION,
		ASSIGNMENT_CHAIN,
		DEFINITION
	> field_1;
	std::optional<std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		TYPE_CONSTRAINT_CHAIN
	>> field_2;
};

#endif //INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP