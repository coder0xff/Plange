// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
#define INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_4;
struct ICR;
struct PLATFORM;

struct FUNCTION_MODIFIER_PLATFORM {
	erased<PLATFORM> field_1;
	std::vector<std::tuple<
		erased<ICR>,
		erased<PLATFORM>
	>> field_2;
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_4>
	>> field_3;


	FUNCTION_MODIFIER_PLATFORM(
		erased<PLATFORM> const & field_1,
		std::vector<std::tuple<
			erased<ICR>,
			erased<PLATFORM>
		>> const & field_2,
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_4>
		>> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}

	static FUNCTION_MODIFIER_PLATFORM build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
