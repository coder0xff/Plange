// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

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
	
		static declaration build(parlex::details::ast_node const & n);
	
	};

	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		declaration,
		erased<EXPRESSION>
	> field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		literal_in_t,
		literal_0xE20x880x88_t
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
			literal_in_t,
			literal_0xE20x880x88_t
		> const & field_5,
		std::vector<erased<IC>> const & field_6,
		erased<EXPRESSION> const & collection,
		std::vector<erased<IC>> const & field_7,
		std::vector<erased<IC>> const & field_8,
		erased<EXPRESSION> const & invoke
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6), collection(collection), field_7(field_7), field_8(field_8), invoke(invoke) {}

	static FOR_COLLECTION build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
