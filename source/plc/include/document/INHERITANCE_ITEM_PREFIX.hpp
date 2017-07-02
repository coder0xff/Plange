// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
#define INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
struct INHERITANCE_ITEM_PREFIX {
	std::variant<
		VISIBILITY_MODIFIER,
		std::tuple<
			VISIBILITY_MODIFIER,
			ICR
		>,
		struct diamond {}
	> field_1;
	ICR field_2;
};

#endif //INCLUDED_INHERITANCE_ITEM_PREFIX_HPP