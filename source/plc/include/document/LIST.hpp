// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LIST_HPP
#define INCLUDED_LIST_HPP

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

struct LIST {
	int32_t document_position, consumed_character_count;

	struct elements_t {
		struct field_2_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C0x20_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<EXPRESSION> field_3;
			
		
		
			explicit field_2_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C0x20_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
		
			field_2_t(field_2_t const & other) = default;
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<EXPRESSION> field_1;
		
		std::vector<field_2_t> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit elements_t
			(val<EXPRESSION> const & field_1, std::vector<field_2_t> const & field_2, std::vector<val<IC>> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		elements_t(elements_t const & other) = default;
		static elements_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B0x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<elements_t> elements;
	
	parlex::detail::document::text<literal_0x7C0x5D_t> dont_care3;
	


	explicit LIST
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x5B0x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<elements_t> const & elements, parlex::detail::document::text<literal_0x7C0x5D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), elements(elements), dont_care3(dont_care3) {}

	LIST(LIST const & other) = default;
	static LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_LIST_HPP
