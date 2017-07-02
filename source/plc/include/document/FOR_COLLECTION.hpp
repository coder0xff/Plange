// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

struct FOR_COLLECTION {
	struct declaration {
		std::optional<std::tuple<
			std::variant<
				erased<TYPE_DEREFERENCE>,
				erased<IMPLICIT_TYPE_DEREFERENCE>
			>,
			std::vector<erased<IC>>
		>> field_1;
		erased<IDENTIFIER> field_2;
	};

	erased<EXPRESSION> collection;
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		declaration,
		erased<EXPRESSION>
	> field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_5;
	std::vector<erased<IC>> field_6;
	std::vector<erased<IC>> field_7;
	std::vector<erased<IC>> field_8;
	erased<EXPRESSION> invoke;
};



#endif //INCLUDED_FOR_COLLECTION_HPP
