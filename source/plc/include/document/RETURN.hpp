// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RETURN_HPP
#define INCLUDED_RETURN_HPP

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

struct RETURN {
	struct field_1_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
		std::vector<erased<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dontCare5;
		
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5B_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x5D_t> && dontCare5) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare5(std::move(dontCare5)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t_1_t {
		std::vector<erased<IC>> field_1;
		
		erased<EXPRESSION> field_2;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_return_t> dontCare0;
	
	std::optional<field_1_t_1_t> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit RETURN(
		parlex::detail::document::text<literal_return_t> && dontCare0, std::optional<field_1_t_1_t> && field_1, std::optional<field_2_t_1_t> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	RETURN(RETURN const & other) = default;
	RETURN(RETURN && move) = default;

	static RETURN build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_RETURN_HPP
