// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_INVOCATION_HPP
#define INCLUDED_PARENTHETICAL_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARGUMENT;
struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct PARENTHETICAL_INVOCATION {
	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>
		> field_2;
		
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1, std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_4_t_1_t {
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
		
			static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		std::vector<erased<IC>> field_1;
		
		std::optional<field_2_t_1_t> field_2;
		
	
	
		explicit field_4_t_1_t(
			std::vector<erased<IC>> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::optional<field_3_t_1_t> field_3;
	
	std::vector<field_4_t_1_t> field_4;
	
	std::vector<erased<IC>> field_5;
	


	explicit PARENTHETICAL_INVOCATION(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::optional<field_3_t_1_t> && field_3, std::vector<field_4_t_1_t> && field_4, std::vector<erased<IC>> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION const & other) = default;
	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION && move) = default;

	static PARENTHETICAL_INVOCATION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_PARENTHETICAL_INVOCATION_HPP
