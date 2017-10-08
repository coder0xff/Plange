// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_FUNCTION_HPP
#define INCLUDED_ASM_FUNCTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_SCOPE;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct ASM_FUNCTION {
	struct field_1_t_1_t {
		struct field_2_t_1_t {
			struct field_1_t_1_t {
				std::vector<erased<IC>> field_1;
				std::vector<erased<IC>> field_2;
				erased<PARAMETER> parameter;
			
			
				explicit field_1_t_1_t(
					std::vector<erased<IC>> && field_1,
					std::vector<erased<IC>> && field_2,
					erased<PARAMETER> && parameter
				) : field_1(std::move(field_1)), field_2(std::move(field_2)), parameter(std::move(parameter)) {}
			
				field_1_t_1_t(field_1_t_1_t const & other) = default;
				field_1_t_1_t(field_1_t_1_t && move) = default;
			
				static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
			
			};
		
			erased<PARAMETER> parameter;
			std::vector<field_1_t_1_t> field_1;
			std::vector<erased<IC>> field_2;
		
		
			explicit field_2_t_1_t(
				erased<PARAMETER> && parameter,
				std::vector<field_1_t_1_t> && field_1,
				std::vector<erased<IC>> && field_2
			) : parameter(std::move(parameter)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
		
		};
	
		std::vector<erased<IC>> field_1;
		std::optional<field_2_t_1_t> field_2;
		std::vector<erased<IC>> field_3;
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1,
			std::optional<field_2_t_1_t> && field_2,
			std::vector<erased<IC>> && field_3
		) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	std::optional<field_1_t_1_t> field_1;
	std::optional<erased<FUNCTION_MODIFIER_0>> field_2;
	std::vector<erased<IC>> field_3;
	erased<ASM_SCOPE> field_4;


	explicit ASM_FUNCTION(
		std::optional<field_1_t_1_t> && field_1,
		std::optional<erased<FUNCTION_MODIFIER_0>> && field_2,
		std::vector<erased<IC>> && field_3,
		erased<ASM_SCOPE> && field_4
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	ASM_FUNCTION(ASM_FUNCTION const & other) = default;
	ASM_FUNCTION(ASM_FUNCTION && move) = default;

	static ASM_FUNCTION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_FUNCTION_HPP
