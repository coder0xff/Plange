// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONTINUE_HPP
#define INCLUDED_CONTINUE_HPP

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
struct ICR;
struct IDENTIFIER;

struct CONTINUE {
	struct field_1_t_1_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> expression;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit field_1_t_1_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), expression(std::move(expression)), field_3(std::move(field_3)) {}
	
		field_1_t_1_t_1_t(field_1_t_1_t_1_t const & other) = default;
		field_1_t_1_t_1_t(field_1_t_1_t_1_t && move) = default;
	
		static field_1_t_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_1_t_1_t_2_t {
		std::vector<erased<ICR>> field_1;
		
		erased<IDENTIFIER> identifier;
		
	
	
		explicit field_1_t_1_t_2_t(
			std::vector<erased<ICR>> && field_1, erased<IDENTIFIER> && identifier) : field_1(std::move(field_1)), identifier(std::move(identifier)) {}
	
		field_1_t_1_t_2_t(field_1_t_1_t_2_t const & other) = default;
		field_1_t_1_t_2_t(field_1_t_1_t_2_t && move) = default;
	
		static field_1_t_1_t_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<std::variant<
		field_1_t_1_t_1_t,
		field_1_t_1_t_2_t
	>> field_1;
	


	explicit CONTINUE(
		std::optional<std::variant<
			field_1_t_1_t_1_t,
			field_1_t_1_t_2_t
		>> && field_1) : field_1(std::move(field_1)) {}

	CONTINUE(CONTINUE const & other) = default;
	CONTINUE(CONTINUE && move) = default;

	static CONTINUE build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CONTINUE_HPP
