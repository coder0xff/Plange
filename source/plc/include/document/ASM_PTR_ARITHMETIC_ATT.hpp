// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct ASM_PTR_ARITHMETIC_ATT_REG;
struct NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_ATT_1_t {
	erased<ASM_IDENTIFIER> field_1;
	
	parlex::detail::document::text<literal_0x3A_t> dontCare1;
	
	erased<NON_FRACTIONAL> field_2;
	


	explicit ASM_PTR_ARITHMETIC_ATT_1_t(
		erased<ASM_IDENTIFIER> && field_1, parlex::detail::document::text<literal_0x3A_t> && dontCare1, erased<NON_FRACTIONAL> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}

	ASM_PTR_ARITHMETIC_ATT_1_t(ASM_PTR_ARITHMETIC_ATT_1_t const & other) = default;
	ASM_PTR_ARITHMETIC_ATT_1_t(ASM_PTR_ARITHMETIC_ATT_1_t && move) = default;

	static ASM_PTR_ARITHMETIC_ATT_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct ASM_PTR_ARITHMETIC_ATT_2_t {
	erased<ASM_IDENTIFIER> field_1;
	
	parlex::detail::document::text<literal_0x3A_t> dontCare1;
	
	erased<NON_FRACTIONAL> field_2;
	
	erased<ASM_PTR_ARITHMETIC_ATT_REG> field_3;
	


	explicit ASM_PTR_ARITHMETIC_ATT_2_t(
		erased<ASM_IDENTIFIER> && field_1, parlex::detail::document::text<literal_0x3A_t> && dontCare1, erased<NON_FRACTIONAL> && field_2, erased<ASM_PTR_ARITHMETIC_ATT_REG> && field_3) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	ASM_PTR_ARITHMETIC_ATT_2_t(ASM_PTR_ARITHMETIC_ATT_2_t const & other) = default;
	ASM_PTR_ARITHMETIC_ATT_2_t(ASM_PTR_ARITHMETIC_ATT_2_t && move) = default;

	static ASM_PTR_ARITHMETIC_ATT_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct ASM_PTR_ARITHMETIC_ATT_3_t {
	erased<NON_FRACTIONAL> field_1;
	
	erased<ASM_PTR_ARITHMETIC_ATT_REG> field_2;
	


	explicit ASM_PTR_ARITHMETIC_ATT_3_t(
		erased<NON_FRACTIONAL> && field_1, erased<ASM_PTR_ARITHMETIC_ATT_REG> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ASM_PTR_ARITHMETIC_ATT_3_t(ASM_PTR_ARITHMETIC_ATT_3_t const & other) = default;
	ASM_PTR_ARITHMETIC_ATT_3_t(ASM_PTR_ARITHMETIC_ATT_3_t && move) = default;

	static ASM_PTR_ARITHMETIC_ATT_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	ASM_PTR_ARITHMETIC_ATT_1_t,
	ASM_PTR_ARITHMETIC_ATT_2_t,
	ASM_PTR_ARITHMETIC_ATT_3_t
> ASM_PTR_ARITHMETIC_ATT_base;

struct ASM_PTR_ARITHMETIC_ATT: ASM_PTR_ARITHMETIC_ATT_base {
	static ASM_PTR_ARITHMETIC_ATT build(parlex::detail::ast_node const & n);
	explicit ASM_PTR_ARITHMETIC_ATT(ASM_PTR_ARITHMETIC_ATT_base const & value) : ASM_PTR_ARITHMETIC_ATT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP
