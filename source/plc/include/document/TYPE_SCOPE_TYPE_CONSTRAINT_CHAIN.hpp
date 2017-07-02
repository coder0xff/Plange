// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
struct TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN {
	std::optional<std::tuple<
		XML_DOC_STRING,
		std::vector<IC>
	>> field_1;
	std::variant<
		TYPE_SCOPE_DECLARATION,
		TYPE_SCOPE_ASSIGNMENT_CHAIN,
		DEFINITION
	> field_2;
	std::optional<std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN
	>> field_3;
};

#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP