// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_NATURAL_HPP
#define INCLUDED_PARAMETER_NATURAL_HPP

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
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

struct PARAMETER_NATURAL1_t {
	struct field_1_t {
		val<TYPE_DEREFERENCE> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(val<TYPE_DEREFERENCE> const & field_1, std::vector<val<IC>> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	val<IDENTIFIER> field_2;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_3;
	


	explicit PARAMETER_NATURAL1_t
		(std::optional<field_1_t> const & field_1, val<IDENTIFIER> const & field_2, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> const & field_3)
		: field_1(field_1), field_2(field_2), field_3(field_3) {}

	PARAMETER_NATURAL1_t(PARAMETER_NATURAL1_t const & other) = default;
	static PARAMETER_NATURAL1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct PARAMETER_NATURAL2_t {
	struct field_1_t {
		std::variant<
			val<TYPE_DEREFERENCE>,
			val<IMPLICIT_TYPE_DEREFERENCE>
		> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(std::variant<
		val<TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>
	> const & field_1, std::vector<val<IC>> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	val<IDENTIFIER> field_2;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_3;
	
	std::vector<val<IC>> field_4;
	
	parlex::detail::document::text<literal_0x3D_t> dont_care4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_7;
	


	explicit PARAMETER_NATURAL2_t
		(std::optional<field_1_t> const & field_1, val<IDENTIFIER> const & field_2, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x3D_t> const & dont_care4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> const & field_7)
		: field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care4(dont_care4), field_5(field_5), field_6(field_6), field_7(field_7) {}

	PARAMETER_NATURAL2_t(PARAMETER_NATURAL2_t const & other) = default;
	static PARAMETER_NATURAL2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	PARAMETER_NATURAL1_t,
	PARAMETER_NATURAL2_t
> PARAMETER_NATURAL_base;

struct PARAMETER_NATURAL: PARAMETER_NATURAL_base {
	static PARAMETER_NATURAL build(parlex::detail::ast_node const & n);
	explicit PARAMETER_NATURAL(PARAMETER_NATURAL_base const & value) : PARAMETER_NATURAL_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_PARAMETER_NATURAL_HPP
