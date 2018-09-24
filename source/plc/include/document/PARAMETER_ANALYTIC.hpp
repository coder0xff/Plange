// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_ANALYTIC_HPP
#define INCLUDED_PARAMETER_ANALYTIC_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct PARAMETER_ANALYTIC {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3D_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> && field_1, parlex::detail::document::text<literal_0x3D_t> && dont_care1, std::vector<val<IC>> && field_2, val<EXPRESSION> && field_3)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<EXPRESSION> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit PARAMETER_ANALYTIC
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && field_1, std::optional<field_2_t> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PARAMETER_ANALYTIC(PARAMETER_ANALYTIC const & other) = default;
	PARAMETER_ANALYTIC(PARAMETER_ANALYTIC && move) = default;

	static PARAMETER_ANALYTIC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PARAMETER_ANALYTIC_HPP
