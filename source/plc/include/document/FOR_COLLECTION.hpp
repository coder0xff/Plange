// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_COLLECTION_HPP
#define INCLUDED_FOR_COLLECTION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

struct FOR_COLLECTION {
	int32_t document_position, consumed_character_count;

	struct declaration {
		struct field_1_t {
			std::variant<
				val<TYPE_DEREFERENCE>,
				val<IMPLICIT_TYPE_DEREFERENCE>
			> field_1;
			
			std::vector<val<IC>> field_2;
			
		
		
			explicit field_1_t
				(std::variant<
			val<TYPE_DEREFERENCE>,
			val<IMPLICIT_TYPE_DEREFERENCE>
		> && field_1, std::vector<val<IC>> && field_2)
				: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_1_t(field_1_t const & other) = default;
			field_1_t(field_1_t && move) = default;
		
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::optional<field_1_t> field_1;
		
		val<IDENTIFIER> field_2;
		
	
	
		explicit declaration
			(std::optional<field_1_t> && field_1, val<IDENTIFIER> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		declaration(declaration const & other) = default;
		declaration(declaration && move) = default;
	
		static declaration build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> field_02;
	
	std::variant<
		declaration,
		val<EXPRESSION>
	> field_03;
	
	std::vector<val<IC>> field_04;
	
	std::variant<
		parlex::detail::document::text<literal_in_t>,
		parlex::detail::document::text<literal_0xE20x880x88_t>
	> field_05;
	
	std::vector<val<IC>> field_06;
	
	val<EXPRESSION> collection;
	
	std::vector<val<IC>> field_07;
	
	parlex::detail::document::text<literal_0x29_t> dont_care10;
	
	std::vector<val<IC>> field_08;
	
	val<EXPRESSION> invoke;
	


	explicit FOR_COLLECTION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> && dont_care0, std::vector<val<IC>> && field_01, parlex::detail::document::text<literal_0x28_t> && dont_care2, std::vector<val<IC>> && field_02, std::variant<
	declaration,
	val<EXPRESSION>
> && field_03, std::vector<val<IC>> && field_04, std::variant<
	parlex::detail::document::text<literal_in_t>,
	parlex::detail::document::text<literal_0xE20x880x88_t>
> && field_05, std::vector<val<IC>> && field_06, val<EXPRESSION> && collection, std::vector<val<IC>> && field_07, parlex::detail::document::text<literal_0x29_t> && dont_care10, std::vector<val<IC>> && field_08, val<EXPRESSION> && invoke)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_01(std::move(field_01)), dont_care2(std::move(dont_care2)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), collection(std::move(collection)), field_07(std::move(field_07)), dont_care10(std::move(dont_care10)), field_08(std::move(field_08)), invoke(std::move(invoke)) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	FOR_COLLECTION(FOR_COLLECTION && move) = default;

	static FOR_COLLECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
