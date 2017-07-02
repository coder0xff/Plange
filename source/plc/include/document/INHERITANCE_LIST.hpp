// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_LIST_HPP
#define INCLUDED_INHERITANCE_LIST_HPP
struct INHERITANCE_LIST {
	EXPRESSION EXPRESSION;
	std::optional<INHERITANCE_ITEM_PREFIX> field_1;
	std::vector<std::tuple<
		std::vector<IC>,
		std::vector<IC>,
		std::optional<INHERITANCE_ITEM_PREFIX>,
		EXPRESSION
	>> field_2;
};

#endif //INCLUDED_INHERITANCE_LIST_HPP