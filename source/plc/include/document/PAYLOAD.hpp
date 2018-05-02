// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PAYLOAD_HPP
#define INCLUDED_PAYLOAD_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct PAYLOAD {
	parlex::detail::document::text<parlex::detail::all_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::all_t>> field_2;
	


	explicit PAYLOAD(
		parlex::detail::document::text<parlex::detail::all_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::all_t>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PAYLOAD(PAYLOAD const & other) = default;
	PAYLOAD(PAYLOAD && move) = default;

	static PAYLOAD build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PAYLOAD_HPP
