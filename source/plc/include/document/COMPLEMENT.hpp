// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMPLEMENT_HPP
#define INCLUDED_COMPLEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct COMPLEMENT {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE10xB60x9C_t> dontCare2;
	


	explicit COMPLEMENT(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0xE10xB60x9C_t> && dontCare2) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)) {}

	COMPLEMENT(COMPLEMENT const & other) = default;
	COMPLEMENT(COMPLEMENT && move) = default;

	static COMPLEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_COMPLEMENT_HPP
