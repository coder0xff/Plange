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
	struct argsTail_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dontCare1;
		
		std::optional<erased<ARRAY_INDEXER>> field_2;
		
	
	
		explicit argsTail_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::optional<erased<ARRAY_INDEXER>> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}
	
		argsTail_t_1_t(argsTail_t_1_t const & other) = default;
		argsTail_t_1_t(argsTail_t_1_t && move) = default;
	
		static argsTail_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	erased<EXPRESSION> target;
	
	parlex::detail::document::text<literal_0x5B_t> dontCare1;
	
	std::optional<erased<ARRAY_INDEXER>> argsHead;
	
	std::vector<argsTail_t_1_t> argsTail;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_0x5D_t> dontCare5;
	


	explicit ARRAY_INVOCATION(
		erased<EXPRESSION> && target, parlex::detail::document::text<literal_0x5B_t> && dontCare1, std::optional<erased<ARRAY_INDEXER>> && argsHead, std::vector<argsTail_t_1_t> && argsTail, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5D_t> && dontCare5) : target(std::move(target)), dontCare1(std::move(dontCare1)), argsHead(std::move(argsHead)), argsTail(std::move(argsTail)), field_1(std::move(field_1)), dontCare5(std::move(dontCare5)) {}

	ARRAY_INVOCATION(ARRAY_INVOCATION const & other) = default;
	ARRAY_INVOCATION(ARRAY_INVOCATION && move) = default;

	static ARRAY_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARRAY_INVOCATION_HPP
