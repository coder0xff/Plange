// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP
struct FOR_COLLECTION {
	struct declaration {
		std::optional<std::tuple<
			std::variant<
				TYPE_DEREFERENCE,
				IMPLICIT_TYPE_DEREFERENCE
			>,
			std::vector<IC>
		>> field_1;
		IDENTIFIER field_2;
	};

	EXPRESSION collection;
	std::vector<IC> field_1;
	std::vector<IC> field_2;
	std::variant<
		declaration,
		EXPRESSION
	> field_3;
	std::vector<IC> field_4;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_5;
	std::vector<IC> field_6;
	std::vector<IC> field_7;
	std::vector<IC> field_8;
	EXPRESSION invoke;
};

#endif //INCLUDED_FOR_COLLECTION_HPP