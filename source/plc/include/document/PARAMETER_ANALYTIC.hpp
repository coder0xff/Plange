// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_ANALYTIC_HPP
#define INCLUDED_PARAMETER_ANALYTIC_HPP

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

struct PARAMETER_ANALYTIC {
	struct field_2_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	erased<EXPRESSION> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit PARAMETER_ANALYTIC(
		erased<EXPRESSION> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PARAMETER_ANALYTIC(PARAMETER_ANALYTIC const & other) = default;
	PARAMETER_ANALYTIC(PARAMETER_ANALYTIC && move) = default;

	static PARAMETER_ANALYTIC build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_PARAMETER_ANALYTIC_HPP
