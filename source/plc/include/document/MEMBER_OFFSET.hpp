// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_OFFSET_HPP
#define INCLUDED_MEMBER_OFFSET_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct WHOLE_NUMBER;

struct MEMBER_OFFSET {
	parlex::detail::document::text<literal_0x40_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<WHOLE_NUMBER> field_2;
	


	explicit MEMBER_OFFSET(
		parlex::detail::document::text<literal_0x40_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<WHOLE_NUMBER> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	MEMBER_OFFSET(MEMBER_OFFSET const & other) = default;
	MEMBER_OFFSET(MEMBER_OFFSET && move) = default;

	static MEMBER_OFFSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MEMBER_OFFSET_HPP
