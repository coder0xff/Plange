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
		> const & field_1, std::vector<val<IC>> const & ic)
				: field_1(field_1), ic(ic) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::optional<field_1_t> field_1;
		
		val<IDENTIFIER> identifier;
		
	
	
		explicit declaration
			(std::optional<field_1_t> const & field_1, val<IDENTIFIER> const & identifier)
			: field_1(field_1), identifier(identifier) {}
	
		declaration(declaration const & other) = default;
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
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> const & dont_care0, std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x28_t> const & dont_care2, std::vector<val<IC>> const & ic2, std::variant<
	declaration,
	val<EXPRESSION>
> const & field_01, std::vector<val<IC>> const & ic3, std::variant<
	parlex::detail::document::text<literal_in_t>,
	parlex::detail::document::text<literal_0xE20x880x88_t>
> const & field_02, std::vector<val<IC>> const & ic4, val<EXPRESSION> const & collection, std::vector<val<IC>> const & ic5, parlex::detail::document::text<literal_0x29_t> const & dont_care10, std::vector<val<IC>> const & ic6, val<EXPRESSION> const & expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), dont_care2(dont_care2), ic2(ic2), field_01(field_01), ic3(ic3), field_02(field_02), ic4(ic4), collection(collection), ic5(ic5), dont_care10(dont_care10), ic6(ic6), expression(expression) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	static FOR_COLLECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_COLLECTION_HPP
