// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IFF_HPP
#define INCLUDED_IFF_HPP

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

struct IFF {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		literal_0xE20x870x94_t,
		literal_0x3C0x3D0x3E_t
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit IFF(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			literal_0xE20x870x94_t,
			literal_0x3C0x3D0x3E_t
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	IFF(IFF const & other) = default;
	IFF(IFF && move) = default;

	static IFF build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_IFF_HPP
