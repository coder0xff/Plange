// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_ARGUMENTS_HPP
#define INCLUDED_ARRAY_ARGUMENTS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY_INDEXER;
struct IC;

struct ARRAY_ARGUMENTS {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		struct field_1_t {
			std::vector<val<IC>> ic;
			
			val<ARRAY_INDEXER> array_indexer;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> && ic, val<ARRAY_INDEXER> && array_indexer)
				: ic(std::move(ic)), array_indexer(std::move(array_indexer)) {}
		
			field_1_t(field_1_t const & other) = default;
			field_1_t(field_1_t && move) = default;
		
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<val<IC>> ic;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::optional<field_1_t> field_1;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> && ic, parlex::detail::document::text<literal_0x2C_t> && comma, std::optional<field_1_t> && field_1)
			: ic(std::move(ic)), comma(std::move(comma)), field_1(std::move(field_1)) {}
	
		tail_t(tail_t const & other) = default;
		tail_t(tail_t && move) = default;
	
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<ARRAY_INDEXER>> head;
	
	std::vector<tail_t> tail;
	


	explicit ARRAY_ARGUMENTS
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<ARRAY_INDEXER>> && head, std::vector<tail_t> && tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), head(std::move(head)), tail(std::move(tail)) {}

	ARRAY_ARGUMENTS(ARRAY_ARGUMENTS const & other) = default;
	ARRAY_ARGUMENTS(ARRAY_ARGUMENTS && move) = default;

	static ARRAY_ARGUMENTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARRAY_ARGUMENTS_HPP
