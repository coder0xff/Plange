// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_PACK_HPP
#define INCLUDED_ARGUMENT_PACK_HPP

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

struct ARGUMENT_PACK {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dontCare2;
	


	explicit ARGUMENT_PACK(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> && dontCare2) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)) {}

	ARGUMENT_PACK(ARGUMENT_PACK const & other) = default;
	ARGUMENT_PACK(ARGUMENT_PACK && move) = default;

	static ARGUMENT_PACK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARGUMENT_PACK_HPP
