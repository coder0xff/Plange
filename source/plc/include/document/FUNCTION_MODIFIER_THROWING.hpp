// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_THROWING_HPP
#define INCLUDED_FUNCTION_MODIFIER_THROWING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY;
struct FUNCTION_MODIFIER_2;
struct IC;
struct ICR;

struct FUNCTION_MODIFIER_THROWING {
	struct field_1_t_1_t {
		std::vector<erased<IC>> field_1;
		
		erased<ARRAY> field_2;
		
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1, erased<ARRAY> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
	};

	struct field_2_t_1_t {
		erased<ICR> field_1;
		
		erased<FUNCTION_MODIFIER_2> field_2;
		
	
	
		explicit field_2_t_1_t(
			erased<ICR> && field_1, erased<FUNCTION_MODIFIER_2> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
	};

	parlex::details::document::text<literal_throwing_t> dontCare0;
	
	std::optional<field_1_t_1_t> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit FUNCTION_MODIFIER_THROWING(
		parlex::details::document::text<literal_throwing_t> && dontCare0, std::optional<field_1_t_1_t> && field_1, std::optional<field_2_t_1_t> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	FUNCTION_MODIFIER_THROWING(FUNCTION_MODIFIER_THROWING const & other) = default;
	FUNCTION_MODIFIER_THROWING(FUNCTION_MODIFIER_THROWING && move) = default;

	static FUNCTION_MODIFIER_THROWING build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_THROWING_HPP
