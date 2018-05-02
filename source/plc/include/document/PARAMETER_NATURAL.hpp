// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_NATURAL_HPP
#define INCLUDED_PARAMETER_NATURAL_HPP

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
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

struct PARAMETER_NATURAL_1_t {
	struct field_1_t_1_t {
		erased<TYPE_DEREFERENCE> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_1_t_1_t(
			erased<TYPE_DEREFERENCE> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t_1_t> field_1;
	
	erased<IDENTIFIER> field_2;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_3;
	


	explicit PARAMETER_NATURAL_1_t(
		std::optional<field_1_t_1_t> && field_1, erased<IDENTIFIER> && field_2, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	PARAMETER_NATURAL_1_t(PARAMETER_NATURAL_1_t const & other) = default;
	PARAMETER_NATURAL_1_t(PARAMETER_NATURAL_1_t && move) = default;

	static PARAMETER_NATURAL_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct PARAMETER_NATURAL_2_t {
	struct field_1_t_1_t {
		std::variant<
			erased<TYPE_DEREFERENCE>,
			erased<IMPLICIT_TYPE_DEREFERENCE>
		> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_1_t_1_t(
			std::variant<
				erased<TYPE_DEREFERENCE>,
				erased<IMPLICIT_TYPE_DEREFERENCE>
			> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t_1_t> field_1;
	
	erased<IDENTIFIER> field_2;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x3D_t> dontCare4;
	
	std::vector<erased<IC>> field_5;
	
	erased<EXPRESSION> field_6;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_7;
	


	explicit PARAMETER_NATURAL_2_t(
		std::optional<field_1_t_1_t> && field_1, erased<IDENTIFIER> && field_2, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x3D_t> && dontCare4, std::vector<erased<IC>> && field_5, erased<EXPRESSION> && field_6, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> && field_7) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare4(std::move(dontCare4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)) {}

	PARAMETER_NATURAL_2_t(PARAMETER_NATURAL_2_t const & other) = default;
	PARAMETER_NATURAL_2_t(PARAMETER_NATURAL_2_t && move) = default;

	static PARAMETER_NATURAL_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	PARAMETER_NATURAL_1_t,
	PARAMETER_NATURAL_2_t
> PARAMETER_NATURAL_base;

struct PARAMETER_NATURAL: PARAMETER_NATURAL_base {
	static PARAMETER_NATURAL build(parlex::detail::ast_node const & n);
	explicit PARAMETER_NATURAL(PARAMETER_NATURAL_base const & value) : PARAMETER_NATURAL_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_PARAMETER_NATURAL_HPP
