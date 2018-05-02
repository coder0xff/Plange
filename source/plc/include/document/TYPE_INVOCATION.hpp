// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_INVOCATION_HPP
#define INCLUDED_TYPE_INVOCATION_HPP

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

struct TYPE_INVOCATION {
	struct field_1_t {
		struct argsHead_t_1_t {
			std::vector<erased<IC>> field_1;
			
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			> field_2;
			
		
		
			explicit argsHead_t_1_t(
				std::vector<erased<IC>> && field_1, std::variant<
					erased<ARGUMENT>,
					erased<ARGUMENT_PACK>
				> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			argsHead_t_1_t(argsHead_t_1_t const & other) = default;
			argsHead_t_1_t(argsHead_t_1_t && move) = default;
		
			static argsHead_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		struct argsTail_t_1_t {
			struct field_2_t_1_t {
				std::vector<erased<IC>> field_1;
				
				std::variant<
					erased<ARGUMENT>,
					erased<ARGUMENT_PACK>
				> field_2;
				
			
			
				explicit field_2_t_1_t(
					std::vector<erased<IC>> && field_1, std::variant<
						erased<ARGUMENT>,
						erased<ARGUMENT_PACK>
					> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
			
				field_2_t_1_t(field_2_t_1_t const & other) = default;
				field_2_t_1_t(field_2_t_1_t && move) = default;
			
				static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dontCare1;
			
			std::optional<field_2_t_1_t> field_2;
			
		
		
			explicit argsTail_t_1_t(
				std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}
		
			argsTail_t_1_t(argsTail_t_1_t const & other) = default;
			argsTail_t_1_t(argsTail_t_1_t && move) = default;
		
			static argsTail_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x3C_t> dontCare0;
		
		std::optional<argsHead_t_1_t> argsHead;
		
		std::vector<argsTail_t_1_t> argsTail;
		
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3E_t> dontCare4;
		
	
	
		explicit field_1_t(
			parlex::detail::document::text<literal_0x3C_t> && dontCare0, std::optional<argsHead_t_1_t> && argsHead, std::vector<argsTail_t_1_t> && argsTail, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x3E_t> && dontCare4) : dontCare0(std::move(dontCare0)), argsHead(std::move(argsHead)), argsTail(std::move(argsTail)), field_1(std::move(field_1)), dontCare4(std::move(dontCare4)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	erased<EXPRESSION> target;
	
	field_1_t field_1;
	


	explicit TYPE_INVOCATION(
		erased<EXPRESSION> && target, field_1_t && field_1) : target(std::move(target)), field_1(std::move(field_1)) {}

	TYPE_INVOCATION(TYPE_INVOCATION const & other) = default;
	TYPE_INVOCATION(TYPE_INVOCATION && move) = default;

	static TYPE_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_INVOCATION_HPP
