// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INVOCATION_HPP
#define INCLUDED_ARRAY_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY_INDEXER;
struct EXPRESSION;
struct IC;

struct ARRAY_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct argsTail_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::optional<erased<ARRAY_INDEXER>> field_2;
		
	
	
		explicit argsTail_t
			(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::optional<erased<ARRAY_INDEXER>> && field_2)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)) {}
	
		argsTail_t(argsTail_t const & other) = default;
		argsTail_t(argsTail_t && move) = default;
	
		static argsTail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	erased<EXPRESSION> target;
	
	parlex::detail::document::text<literal_0x5B_t> dont_care1;
	
	std::optional<erased<ARRAY_INDEXER>> argsHead;
	
	std::vector<argsTail_t> argsTail;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_0x5D_t> dont_care5;
	


	explicit ARRAY_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, erased<EXPRESSION> && target, parlex::detail::document::text<literal_0x5B_t> && dont_care1, std::optional<erased<ARRAY_INDEXER>> && argsHead, std::vector<argsTail_t> && argsTail, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5D_t> && dont_care5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), target(std::move(target)), dont_care1(std::move(dont_care1)), argsHead(std::move(argsHead)), argsTail(std::move(argsTail)), field_1(std::move(field_1)), dont_care5(std::move(dont_care5)) {}

	ARRAY_INVOCATION(ARRAY_INVOCATION const & other) = default;
	ARRAY_INVOCATION(ARRAY_INVOCATION && move) = default;

	static ARRAY_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARRAY_INVOCATION_HPP
