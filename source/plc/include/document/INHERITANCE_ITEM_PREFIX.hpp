﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
#define INCLUDED_INHERITANCE_ITEM_PREFIX_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ICR;
struct VISIBILITY_MODIFIER;

struct INHERITANCE_ITEM_PREFIX {
	struct field_1_t_2_t {
		erased<VISIBILITY_MODIFIER> field_1;
		
		erased<ICR> field_2;
		
		parlex::detail::document::text<literal_diamond_t> dontCare2;
		
	
	
		explicit field_1_t_2_t(
			erased<VISIBILITY_MODIFIER> && field_1, erased<ICR> && field_2, parlex::detail::document::text<literal_diamond_t> && dontCare2) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)) {}
	
		field_1_t_2_t(field_1_t_2_t const & other) = default;
		field_1_t_2_t(field_1_t_2_t && move) = default;
	
		static field_1_t_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		erased<VISIBILITY_MODIFIER>,
		field_1_t_2_t,
		parlex::detail::document::text<literal_diamond_t>
	> field_1;
	
	erased<ICR> field_2;
	


	explicit INHERITANCE_ITEM_PREFIX(
		std::variant<
			erased<VISIBILITY_MODIFIER>,
			field_1_t_2_t,
			parlex::detail::document::text<literal_diamond_t>
		> && field_1, erased<ICR> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	INHERITANCE_ITEM_PREFIX(INHERITANCE_ITEM_PREFIX const & other) = default;
	INHERITANCE_ITEM_PREFIX(INHERITANCE_ITEM_PREFIX && move) = default;

	static INHERITANCE_ITEM_PREFIX build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
