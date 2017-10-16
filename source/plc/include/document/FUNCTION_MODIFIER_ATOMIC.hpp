// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
#define INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_3;
struct ICR;

struct FUNCTION_MODIFIER_ATOMIC {
	struct field_1_t_1_t {
		erased<ICR> field_1;
		
		erased<FUNCTION_MODIFIER_3> field_2;
		
	
	
		explicit field_1_t_1_t(
			erased<ICR> && field_1, erased<FUNCTION_MODIFIER_3> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<field_1_t_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_ATOMIC(
		std::optional<field_1_t_1_t> && field_1) : field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_ATOMIC(FUNCTION_MODIFIER_ATOMIC const & other) = default;
	FUNCTION_MODIFIER_ATOMIC(FUNCTION_MODIFIER_ATOMIC && move) = default;

	static FUNCTION_MODIFIER_ATOMIC build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
