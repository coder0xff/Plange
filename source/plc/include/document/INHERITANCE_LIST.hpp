// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_LIST_HPP
#define INCLUDED_INHERITANCE_LIST_HPP

struct EXPRESSION;
struct IC;
struct INHERITANCE_ITEM_PREFIX;

struct INHERITANCE_LIST {
	erased<EXPRESSION> EXPRESSION;
	std::optional<erased<INHERITANCE_ITEM_PREFIX>> field_1;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		std::optional<erased<INHERITANCE_ITEM_PREFIX>>,
		erased<EXPRESSION>
	>> field_2;
};



#endif //INCLUDED_INHERITANCE_LIST_HPP
