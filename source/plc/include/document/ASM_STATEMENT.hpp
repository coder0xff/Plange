// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_STATEMENT_HPP
#define INCLUDED_ASM_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_EXPRESSION;
struct ASM_OP;
struct IC;

struct ASM_STATEMENT {
	struct field_2_t_1_t {
		struct field_3_t_1_t {
			struct field_2_t_1_t {
				std::vector<erased<IC>> field_1;
				
				erased<ASM_EXPRESSION> field_2;
				
			
			
				explicit field_2_t_1_t(
					std::vector<erased<IC>> && field_1, erased<ASM_EXPRESSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
			
				field_2_t_1_t(field_2_t_1_t const & other) = default;
				field_2_t_1_t(field_2_t_1_t && move) = default;
			
				static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dontCare1;
			
			std::optional<field_2_t_1_t> field_2;
			
		
		
			explicit field_3_t_1_t(
				std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}
		
			field_3_t_1_t(field_3_t_1_t const & other) = default;
			field_3_t_1_t(field_3_t_1_t && move) = default;
		
			static field_3_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<erased<IC>> field_1;
		
		erased<ASM_EXPRESSION> field_2;
		
		std::vector<field_3_t_1_t> field_3;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, erased<ASM_EXPRESSION> && field_2, std::vector<field_3_t_1_t> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	erased<ASM_OP> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0x0A_t> dontCare3;
	


	explicit ASM_STATEMENT(
		erased<ASM_OP> && field_1, std::optional<field_2_t_1_t> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x0A_t> && dontCare3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare3(std::move(dontCare3)) {}

	ASM_STATEMENT(ASM_STATEMENT const & other) = default;
	ASM_STATEMENT(ASM_STATEMENT && move) = default;

	static ASM_STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_STATEMENT_HPP
