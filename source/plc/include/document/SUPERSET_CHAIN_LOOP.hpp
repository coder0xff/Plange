// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUPERSET_CHAIN_LOOP_HPP
#define INCLUDED_SUPERSET_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct SUPERSET_CHAIN_LOOP;

struct SUPERSET_CHAIN_LOOP {
	std::variant<
		literal_0x3D_t,
		literal_0xE20x8A0x87_t,
		literal_sups_t,
		literal_0xE20x8A0x83_t,
		literal_psups_t
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<SUPERSET_CHAIN_LOOP>
	>> field_4;


	SUPERSET_CHAIN_LOOP(
		std::variant<
			literal_0x3D_t,
			literal_0xE20x8A0x87_t,
			literal_sups_t,
			literal_0xE20x8A0x83_t,
			literal_psups_t
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<SUPERSET_CHAIN_LOOP>
		>> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static std::optional<SUPERSET_CHAIN_LOOP> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_SUPERSET_CHAIN_LOOP_HPP
