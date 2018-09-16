// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SET_HPP
#define INCLUDED_SET_HPP

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

struct SET {
	int32_t document_position, consumed_character_count;

	struct elements_t {
		struct field_2_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> field_3;
			
		
		
			explicit field_2_t
				(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3)
				: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
		
			field_2_t(field_2_t const & other) = default;
			field_2_t(field_2_t && move) = default;
		
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		erased<EXPRESSION> field_1;
		
		std::vector<field_2_t> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit elements_t
			(erased<EXPRESSION> && field_1, std::vector<field_2_t> && field_2, std::vector<erased<IC>> && field_3)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		elements_t(elements_t const & other) = default;
		elements_t(elements_t && move) = default;
	
		static elements_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x7B0x7C_t> dont_care0;
	
	std::vector<erased<IC>> field_1;
	
	std::optional<elements_t> elements;
	
	parlex::detail::document::text<literal_0x7C0x7D_t> dont_care3;
	


	explicit SET
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B0x7C_t> && dont_care0, std::vector<erased<IC>> && field_1, std::optional<elements_t> && elements, parlex::detail::document::text<literal_0x7C0x7D_t> && dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), elements(std::move(elements)), dont_care3(std::move(dont_care3)) {}

	SET(SET const & other) = default;
	SET(SET && move) = default;

	static SET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SET_HPP
