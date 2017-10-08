// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_OFFSET_HPP
#define INCLUDED_MEMBER_OFFSET_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct WHOLE_NUMBER;

struct MEMBER_OFFSET {
	std::vector<erased<IC>> field_1;
	erased<WHOLE_NUMBER> field_2;


	explicit MEMBER_OFFSET(
		std::vector<erased<IC>> && field_1,
		erased<WHOLE_NUMBER> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	MEMBER_OFFSET(MEMBER_OFFSET const & other) = default;
	MEMBER_OFFSET(MEMBER_OFFSET && move) = default;

	static MEMBER_OFFSET build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_MEMBER_OFFSET_HPP
