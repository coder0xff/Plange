// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_FUNCTION_HPP
#define INCLUDED_ASM_FUNCTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASM_SCOPE;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct ASM_FUNCTION {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::optional<std::tuple<
			erased<PARAMETER>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<PARAMETER>
			>>,
			std::vector<erased<IC>>
		>>,
		std::vector<erased<IC>>
	>> field_1;
	std::optional<erased<FUNCTION_MODIFIER_0>> field_2;
	std::vector<erased<IC>> field_3;
	erased<ASM_SCOPE> field_4;


	ASM_FUNCTION(
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::optional<std::tuple<
				erased<PARAMETER>,
				std::vector<std::tuple<
					std::vector<erased<IC>>,
					std::vector<erased<IC>>,
					erased<PARAMETER>
				>>,
				std::vector<erased<IC>>
			>>,
			std::vector<erased<IC>>
		>> const & field_1,
		std::optional<erased<FUNCTION_MODIFIER_0>> const & field_2,
		std::vector<erased<IC>> const & field_3,
		erased<ASM_SCOPE> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static ASM_FUNCTION build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_FUNCTION_HPP
