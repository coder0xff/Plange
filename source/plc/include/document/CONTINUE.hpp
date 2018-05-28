// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONTINUE_HPP
#define INCLUDED_CONTINUE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;

struct CONTINUE {
	struct field_1_t_1_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> expression;
		
		std::vector<erased<IC>> field_3;
		
		parlex::detail::document::text<literal_0x5D_t> dontCare5;
		
	
	
		explicit field_1_t_1_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5B_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && expression, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x5D_t> && dontCare5) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), expression(std::move(expression)), field_3(std::move(field_3)), dontCare5(std::move(dontCare5)) {}
	
		field_1_t_1_t_1_t(field_1_t_1_t_1_t const & other) = default;
		field_1_t_1_t_1_t(field_1_t_1_t_1_t && move) = default;
	
		static field_1_t_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t_1_t_2_t {
		erased<IC> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<IDENTIFIER> identifier;
		
	
	
		explicit field_1_t_1_t_2_t(
			erased<IC> && field_1, std::vector<erased<IC>> && field_2, erased<IDENTIFIER> && identifier) : field_1(std::move(field_1)), field_2(std::move(field_2)), identifier(std::move(identifier)) {}
	
		field_1_t_1_t_2_t(field_1_t_1_t_2_t const & other) = default;
		field_1_t_1_t_2_t(field_1_t_1_t_2_t && move) = default;
	
		static field_1_t_1_t_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_continue_t> dontCare0;
	
	std::optional<std::variant<
		field_1_t_1_t_1_t,
		field_1_t_1_t_2_t
	>> field_1;
	


	explicit CONTINUE(
		parlex::detail::document::text<literal_continue_t> && dontCare0, std::optional<std::variant<
			field_1_t_1_t_1_t,
			field_1_t_1_t_2_t
		>> && field_1) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)) {}

	CONTINUE(CONTINUE const & other) = default;
	CONTINUE(CONTINUE && move) = default;

	static CONTINUE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CONTINUE_HPP
