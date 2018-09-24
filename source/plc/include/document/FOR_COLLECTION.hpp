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
			
			std::vector<val<IC>> ic;
			
		
		
			explicit field_1_t
				(std::variant<
			val<TYPE_DEREFERENCE>,
			val<IMPLICIT_TYPE_DEREFERENCE>
		> && field_1, std::vector<val<IC>> && ic)
				: field_1(std::move(field_1)), ic(std::move(ic)) {}
		
			field_1_t(field_1_t const & other) = default;
			field_1_t(field_1_t && move) = default;
		
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::optional<field_1_t> field_1;
		
		val<IDENTIFIER> identifier;
		
	
	
		explicit declaration
			(std::optional<field_1_t> && field_1, val<IDENTIFIER> && identifier)
			: field_1(std::move(field_1)), identifier(std::move(identifier)) {}
	
		declaration(declaration const & other) = default;
		declaration(declaration && move) = default;
	
		static declaration build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> ic2;
	
	std::variant<
		declaration,
		val<EXPRESSION>
	> field_01;
	
	std::vector<val<IC>> ic3;
	
	std::variant<
		parlex::detail::document::text<literal_in_t>,
		parlex::detail::document::text<literal_0xE20x880x88_t>
	> field_02;
	
	std::vector<val<IC>> ic4;
	
	val<EXPRESSION> collection;
	
	std::vector<val<IC>> ic5;
	
	parlex::detail::document::text<literal_0x29_t> dont_care10;
	
	std::vector<val<IC>> ic6;
	
	val<EXPRESSION> expression;
	


	explicit FOR_COLLECTION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> && dont_care0, std::vector<val<IC>> && ic1, parlex::detail::document::text<literal_0x28_t> && dont_care2, std::vector<val<IC>> && ic2, std::variant<
	declaration,
	val<EXPRESSION>
> && field_01, std::vector<val<IC>> && ic3, std::variant<
	parlex::detail::document::text<literal_in_t>,
	parlex::detail::document::text<literal_0xE20x880x88_t>
> && field_02, std::vector<val<IC>> && ic4, val<EXPRESSION> && collection, std::vector<val<IC>> && ic5, parlex::detail::document::text<literal_0x29_t> && dont_care10, std::vector<val<IC>> && ic6, val<EXPRESSION> && expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), ic1(std::move(ic1)), dont_care2(std::move(dont_care2)), ic2(std::move(ic2)), field_01(std::move(field_01)), ic3(std::move(ic3)), field_02(std::move(field_02)), ic4(std::move(ic4)), collection(std::move(collection)), ic5(std::move(ic5)), dont_care10(std::move(dont_care10)), ic6(std::move(ic6)), expression(std::move(expression)) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	FOR_COLLECTION(FOR_COLLECTION && move) = default;

	static FOR_COLLECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
