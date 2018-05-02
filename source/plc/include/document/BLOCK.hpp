// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BLOCK_HPP
#define INCLUDED_BLOCK_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct STATEMENT_SCOPE;

struct BLOCK {
	parlex::detail::document::text<literal_0x7B_t> dontCare0;
	
	erased<STATEMENT_SCOPE> field_1;
	
	parlex::detail::document::text<literal_0x7D_t> dontCare2;
	


	explicit BLOCK(
		parlex::detail::document::text<literal_0x7B_t> && dontCare0, erased<STATEMENT_SCOPE> && field_1, parlex::detail::document::text<literal_0x7D_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	BLOCK(BLOCK const & other) = default;
	BLOCK(BLOCK && move) = default;

	static BLOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_BLOCK_HPP
