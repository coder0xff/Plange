// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WS_HPP
#define INCLUDED_WS_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct WS {
	parlex::details::document::built_in_terminal<parlex::details::white_space_t> field_1;
	
	std::vector<parlex::details::document::built_in_terminal<parlex::details::white_space_t>> field_2;
	


	explicit WS(
		parlex::details::document::built_in_terminal<parlex::details::white_space_t> && field_1, std::vector<parlex::details::document::built_in_terminal<parlex::details::white_space_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	WS(WS const & other) = default;
	WS(WS && move) = default;

	static WS build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_WS_HPP
