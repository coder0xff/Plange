// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TUPLE_HPP
#define INCLUDED_TUPLE_HPP

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

struct TUPLE {
	int32_t document_position, consumed_character_count;

	struct field_3_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
	
	
		explicit field_3_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x280x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<field_3_t> field_3;
	
	std::vector<val<IC>> field_4;
	
	parlex::detail::document::text<literal_0x7C0x29_t> dont_care5;
	


	explicit TUPLE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x280x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<field_3_t> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x7C0x29_t> const & dont_care5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}

	TUPLE(TUPLE const & other) = default;
	static TUPLE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TUPLE_HPP
