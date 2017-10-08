// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
#define INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_4;
struct ICR;
struct PLATFORM;

struct FUNCTION_MODIFIER_PLATFORM {
	struct field_2_t_1_t {
		erased<ICR> field_1;
		erased<PLATFORM> field_2;
	
	
		explicit field_2_t_1_t(
			erased<ICR> && field_1,
			erased<PLATFORM> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_3_t_1_t {
		erased<ICR> field_1;
		erased<FUNCTION_MODIFIER_4> field_2;
	
	
		explicit field_3_t_1_t(
			erased<ICR> && field_1,
			erased<FUNCTION_MODIFIER_4> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	erased<PLATFORM> field_1;
	std::vector<field_2_t_1_t> field_2;
	std::optional<field_3_t_1_t> field_3;


	explicit FUNCTION_MODIFIER_PLATFORM(
		erased<PLATFORM> && field_1,
		std::vector<field_2_t_1_t> && field_2,
		std::optional<field_3_t_1_t> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	FUNCTION_MODIFIER_PLATFORM(FUNCTION_MODIFIER_PLATFORM const & other) = default;
	FUNCTION_MODIFIER_PLATFORM(FUNCTION_MODIFIER_PLATFORM && move) = default;

	static FUNCTION_MODIFIER_PLATFORM build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
