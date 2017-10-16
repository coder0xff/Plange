// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

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
				> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		std::optional<field_1_t_1_t> field_1;
		
		erased<IDENTIFIER> field_2;
		
	
	
		explicit declaration(
			std::optional<field_1_t_1_t> && field_1, erased<IDENTIFIER> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		declaration(declaration const & other) = default;
		declaration(declaration && move) = default;
	
		static declaration build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_01;
	
	std::vector<erased<IC>> field_02;
	
	std::variant<
		declaration,
		erased<EXPRESSION>
	> field_03;
	
	std::vector<erased<IC>> field_04;
	
	std::variant<
		literal_in_t,
		literal_0xE20x880x88_t
	> field_05;
	
	std::vector<erased<IC>> field_06;
	
	erased<EXPRESSION> collection;
	
	std::vector<erased<IC>> field_07;
	
	std::vector<erased<IC>> field_08;
	
	erased<EXPRESSION> invoke;
	


	explicit FOR_COLLECTION(
		std::vector<erased<IC>> && field_01, std::vector<erased<IC>> && field_02, std::variant<
			declaration,
			erased<EXPRESSION>
		> && field_03, std::vector<erased<IC>> && field_04, std::variant<
			literal_in_t,
			literal_0xE20x880x88_t
		> && field_05, std::vector<erased<IC>> && field_06, erased<EXPRESSION> && collection, std::vector<erased<IC>> && field_07, std::vector<erased<IC>> && field_08, erased<EXPRESSION> && invoke) : field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), collection(std::move(collection)), field_07(std::move(field_07)), field_08(std::move(field_08)), invoke(std::move(invoke)) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	FOR_COLLECTION(FOR_COLLECTION && move) = default;

	static FOR_COLLECTION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
