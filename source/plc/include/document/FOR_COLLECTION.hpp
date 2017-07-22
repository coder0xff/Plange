// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

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
	
		declaration(
			std::optional<std::tuple<
				std::variant<
					erased<TYPE_DEREFERENCE>,
					erased<IMPLICIT_TYPE_DEREFERENCE>
				>,
				std::vector<erased<IC>>
			>> const & field_1,
			erased<IDENTIFIER> const & field_2
		) : field_1(field_1), field_2(field_2) {}
	};

	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		declaration,
		erased<EXPRESSION>
	> field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_5;
	std::vector<erased<IC>> field_6;
	erased<EXPRESSION> collection;
	std::vector<erased<IC>> field_7;
	std::vector<erased<IC>> field_8;
	erased<EXPRESSION> invoke;

	FOR_COLLECTION(
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			declaration,
			erased<EXPRESSION>
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_5,
		std::vector<erased<IC>> const & field_6,
		erased<EXPRESSION> const & collection,
		std::vector<erased<IC>> const & field_7,
		std::vector<erased<IC>> const & field_8,
		erased<EXPRESSION> const & invoke
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6), collection(collection), field_7(field_7), field_8(field_8), invoke(invoke) {}
};



#endif //INCLUDED_FOR_COLLECTION_HPP
