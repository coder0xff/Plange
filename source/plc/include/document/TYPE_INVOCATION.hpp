// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_INVOCATION_HPP
#define INCLUDED_TYPE_INVOCATION_HPP

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

struct TYPE_INVOCATION {
	struct field_2_t {
		struct head_t_1_t {
			std::vector<erased<IC>> field_1;
			
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			> field_2;
			
		
		
			explicit head_t_1_t(
				std::vector<erased<IC>> && field_1, std::variant<
					erased<ARGUMENT>,
					erased<ARGUMENT_PACK>
				> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			head_t_1_t(head_t_1_t const & other) = default;
			head_t_1_t(head_t_1_t && move) = default;
		
			static head_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		struct field_1_t_1_t {
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
			
		
		
			explicit field_1_t_1_t(
				std::vector<erased<IC>> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		std::optional<head_t_1_t> head;
		
		std::vector<field_1_t_1_t> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_2_t(
			std::optional<head_t_1_t> && head, std::vector<field_1_t_1_t> && field_1, std::vector<erased<IC>> && field_2) : head(std::move(head)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	erased<EXPRESSION> field_1;
	
	field_2_t field_2;
	


	explicit TYPE_INVOCATION(
		erased<EXPRESSION> && field_1, field_2_t && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	TYPE_INVOCATION(TYPE_INVOCATION const & other) = default;
	TYPE_INVOCATION(TYPE_INVOCATION && move) = default;

	static TYPE_INVOCATION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_INVOCATION_HPP
