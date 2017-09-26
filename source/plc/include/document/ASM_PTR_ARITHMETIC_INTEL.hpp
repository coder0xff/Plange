// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_INTEGER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_INTEL {
	std::optional<std::tuple<
		std::variant<
			literal_BYTE_t,
			literal_WORD_t,
			literal_DWORD_t,
			literal_QWORD_t
		>
	>> field_1;
	std::optional<std::tuple<
		erased<ASM_IDENTIFIER>
	>> field_2;
	erased<ASM_IDENTIFIER> field_3;
	std::optional<std::tuple<
		erased<ASM_IDENTIFIER>,
		std::optional<std::tuple<
			erased<NON_NEG_NON_FRACTIONAL>
		>>
	>> field_4;
	std::optional<std::tuple<
		std::variant<
			literal_0x2B_t,
			literal_0x2D_t
		>,
		erased<NON_NEG_INTEGER>
	>> field_5;


	ASM_PTR_ARITHMETIC_INTEL(
		std::optional<std::tuple<
			std::variant<
				literal_BYTE_t,
				literal_WORD_t,
				literal_DWORD_t,
				literal_QWORD_t
			>
		>> const & field_1,
		std::optional<std::tuple<
			erased<ASM_IDENTIFIER>
		>> const & field_2,
		erased<ASM_IDENTIFIER> const & field_3,
		std::optional<std::tuple<
			erased<ASM_IDENTIFIER>,
			std::optional<std::tuple<
				erased<NON_NEG_NON_FRACTIONAL>
			>>
		>> const & field_4,
		std::optional<std::tuple<
			std::variant<
				literal_0x2B_t,
				literal_0x2D_t
			>,
			erased<NON_NEG_INTEGER>
		>> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static std::optional<ASM_PTR_ARITHMETIC_INTEL> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
