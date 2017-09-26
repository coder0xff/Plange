// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DOT_PRODUCT_HPP
#define INCLUDED_DOT_PRODUCT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct DOT_PRODUCT {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		literal_0xE20x8B0x85_t,
		literal__dot__t
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	DOT_PRODUCT(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			literal_0xE20x8B0x85_t,
			literal__dot__t
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static std::optional<DOT_PRODUCT> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_DOT_PRODUCT_HPP
