// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

struct FOR_COLLECTION {
	struct declaration {
		struct field_1_t_1_t {
			std::variant<
				erased<TYPE_DEREFERENCE>,
				erased<IMPLICIT_TYPE_DEREFERENCE>
			> field_1;
			std::vector<erased<IC>> field_2;
		
		
			explicit field_1_t_1_t(
				std::variant<
					erased<TYPE_DEREFERENCE>,
					erased<IMPLICIT_TYPE_DEREFERENCE>
				> && field_1,
				std::vector<erased<IC>> && field_2
			) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
		
		};
	
		std::optional<field_1_t_1_t> field_1;
		erased<IDENTIFIER> field_2;
	
	
		explicit declaration(
			std::optional<field_1_t_1_t> && field_1,
			erased<IDENTIFIER> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		declaration(declaration const & other) = default;
		declaration(declaration && move) = default;
	
		static declaration build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_5_t {
		enum type {
			literal_0xE20x880x88,
			literal_in
		} value;
	
		static field_5_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0xE20x880x88"), literal_0xE20x880x88 },
				{ &plange_grammar().get_literal("literal_in"), literal_in },
			};
			return field_5_t{ table.find(&n.r)->second };
		}
	};


	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		declaration,
		erased<EXPRESSION>
	> field_3;
	std::vector<erased<IC>> field_4;
	field_5_t field_5;
	std::vector<erased<IC>> field_6;
	erased<EXPRESSION> collection;
	std::vector<erased<IC>> field_7;
	std::vector<erased<IC>> field_8;
	erased<EXPRESSION> invoke;


	explicit FOR_COLLECTION(
		std::vector<erased<IC>> && field_1,
		std::vector<erased<IC>> && field_2,
		std::variant<
			declaration,
			erased<EXPRESSION>
		> && field_3,
		std::vector<erased<IC>> && field_4,
		field_5_t && field_5,
		std::vector<erased<IC>> && field_6,
		erased<EXPRESSION> && collection,
		std::vector<erased<IC>> && field_7,
		std::vector<erased<IC>> && field_8,
		erased<EXPRESSION> && invoke
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)), collection(std::move(collection)), field_7(std::move(field_7)), field_8(std::move(field_8)), invoke(std::move(invoke)) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	FOR_COLLECTION(FOR_COLLECTION && move) = default;

	static FOR_COLLECTION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
