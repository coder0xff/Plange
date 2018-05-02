// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMMENT_HPP
#define INCLUDED_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct COMMENT {
	parlex::detail::document::text<literal_0x2F0x2A_t> dontCare0;
	
	std::vector<parlex::detail::document::text<parlex::detail::all_t>> field_1;
	
	parlex::detail::document::text<literal_0x2A0x2F_t> dontCare2;
	


	explicit COMMENT(
		parlex::detail::document::text<literal_0x2F0x2A_t> && dontCare0, std::vector<parlex::detail::document::text<parlex::detail::all_t>> && field_1, parlex::detail::document::text<literal_0x2A0x2F_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	COMMENT(COMMENT const & other) = default;
	COMMENT(COMMENT && move) = default;

	static COMMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_COMMENT_HPP
