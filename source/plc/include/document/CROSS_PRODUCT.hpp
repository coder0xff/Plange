// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CROSS_PRODUCT_HPP
#define INCLUDED_CROSS_PRODUCT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct CROSS_PRODUCT {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		literal_0xC30x97_t,
		literal__x__t
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit CROSS_PRODUCT(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			literal_0xC30x97_t,
			literal__x__t
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	CROSS_PRODUCT(CROSS_PRODUCT const & other) = default;
	CROSS_PRODUCT(CROSS_PRODUCT && move) = default;

	static CROSS_PRODUCT build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CROSS_PRODUCT_HPP
