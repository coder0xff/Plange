// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
#define INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_4;
struct IC;
struct PLATFORM;

struct FUNCTION_MODIFIER_PLATFORM {
	struct field_2_t_1_t {
		erased<IC> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<PLATFORM> field_3;
		
	
	
		explicit field_2_t_1_t(
			erased<IC> && field_1, std::vector<erased<IC>> && field_2, erased<PLATFORM> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t_1_t {
		erased<IC> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<FUNCTION_MODIFIER_4> field_3;
		
	
	
		explicit field_3_t_1_t(
			erased<IC> && field_1, std::vector<erased<IC>> && field_2, erased<FUNCTION_MODIFIER_4> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	erased<PLATFORM> field_1;
	
	std::vector<field_2_t_1_t> field_2;
	
	std::optional<field_3_t_1_t> field_3;
	


	explicit FUNCTION_MODIFIER_PLATFORM(
		erased<PLATFORM> && field_1, std::vector<field_2_t_1_t> && field_2, std::optional<field_3_t_1_t> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	FUNCTION_MODIFIER_PLATFORM(FUNCTION_MODIFIER_PLATFORM const & other) = default;
	FUNCTION_MODIFIER_PLATFORM(FUNCTION_MODIFIER_PLATFORM && move) = default;

	static FUNCTION_MODIFIER_PLATFORM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
