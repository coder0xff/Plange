// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LESSER_CHAIN_LOOP_HPP
#define INCLUDED_LESSER_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct LESSER_CHAIN_LOOP;

struct LESSER_CHAIN_LOOP {
	std::variant<
		literal_0x3D_t,
		literal_0x3C_t,
		literal_0x3D0x3C_t,
		literal_0xE20x890xA4_t
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<LESSER_CHAIN_LOOP>
	>> field_4;


	LESSER_CHAIN_LOOP(
		std::variant<
			literal_0x3D_t,
			literal_0x3C_t,
			literal_0x3D0x3C_t,
			literal_0xE20x890xA4_t
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<LESSER_CHAIN_LOOP>
		>> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static LESSER_CHAIN_LOOP build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_LESSER_CHAIN_LOOP_HPP
