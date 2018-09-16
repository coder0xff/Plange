// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TUPLE_HPP
#define INCLUDED_TUPLE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

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
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
	
	
		explicit field_3_t
			(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_3_t(field_3_t const & other) = default;
		field_3_t(field_3_t && move) = default;
	
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x280x7C_t> dont_care0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<field_3_t> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x7C0x29_t> dont_care5;
	


	explicit TUPLE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x280x7C_t> && dont_care0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<field_3_t> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x7C0x29_t> && dont_care5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dont_care5(std::move(dont_care5)) {}

	TUPLE(TUPLE const & other) = default;
	TUPLE(TUPLE && move) = default;

	static TUPLE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TUPLE_HPP
