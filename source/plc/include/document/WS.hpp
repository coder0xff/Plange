// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WS_HPP
#define INCLUDED_WS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct WS {
	parlex::detail::document::text<parlex::detail::white_space_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::white_space_t>> field_2;
	


	explicit WS(
		parlex::detail::document::text<parlex::detail::white_space_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::white_space_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	WS(WS const & other) = default;
	WS(WS && move) = default;

	static WS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_WS_HPP
