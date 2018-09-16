// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_INVOCATION_HPP
#define INCLUDED_PARENTHETICAL_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARGUMENT;
struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct PARENTHETICAL_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct argsHead_t {
		std::vector<erased<IC>> field_1;
		
		std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>
		> field_2;
		
	
	
		explicit argsHead_t
			(std::vector<erased<IC>> && field_1, std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>
	> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		argsHead_t(argsHead_t const & other) = default;
		argsHead_t(argsHead_t && move) = default;
	
		static argsHead_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct argsTail_t {
		struct field_2_t {
			std::vector<erased<IC>> field_1;
			
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			> field_2;
			
		
		
			explicit field_2_t
				(std::vector<erased<IC>> && field_1, std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>
		> && field_2)
				: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_2_t(field_2_t const & other) = default;
			field_2_t(field_2_t && move) = default;
		
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::optional<field_2_t> field_2;
		
	
	
		explicit argsTail_t
			(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::optional<field_2_t> && field_2)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)) {}
	
		argsTail_t(argsTail_t const & other) = default;
		argsTail_t(argsTail_t && move) = default;
	
		static argsTail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	erased<EXPRESSION> target;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::optional<argsHead_t> argsHead;
	
	std::vector<argsTail_t> argsTail;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0x29_t> dont_care6;
	


	explicit PARENTHETICAL_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, erased<EXPRESSION> && target, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x28_t> && dont_care2, std::optional<argsHead_t> && argsHead, std::vector<argsTail_t> && argsTail, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0x29_t> && dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), target(std::move(target)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)), argsHead(std::move(argsHead)), argsTail(std::move(argsTail)), field_2(std::move(field_2)), dont_care6(std::move(dont_care6)) {}

	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION const & other) = default;
	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION && move) = default;

	static PARENTHETICAL_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PARENTHETICAL_INVOCATION_HPP
