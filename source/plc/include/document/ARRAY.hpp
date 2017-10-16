// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_HPP
#define INCLUDED_ARRAY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct ARRAY {
	struct field_2_t_1_t {
		struct field_1_t_1_t {
			std::vector<erased<IC>> field_1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> expression;
			
		
		
			explicit field_1_t_1_t(
				std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && expression) : field_1(std::move(field_1)), field_2(std::move(field_2)), expression(std::move(expression)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		erased<EXPRESSION> expression;
		
		std::vector<field_1_t_1_t> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_2_t_1_t(
			erased<EXPRESSION> && expression, std::vector<field_1_t_1_t> && field_1, std::vector<erased<IC>> && field_2) : expression(std::move(expression)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit ARRAY(
		std::vector<erased<IC>> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ARRAY(ARRAY const & other) = default;
	ARRAY(ARRAY && move) = default;

	static ARRAY build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ARRAY_HPP
