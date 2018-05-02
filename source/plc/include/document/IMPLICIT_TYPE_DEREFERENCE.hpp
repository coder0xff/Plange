// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP

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

struct IMPLICIT_TYPE_DEREFERENCE {
	parlex::detail::document::text<literal_0x3C_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_0x3E_t> dontCare2;
	


	explicit IMPLICIT_TYPE_DEREFERENCE(
		parlex::detail::document::text<literal_0x3C_t> && dontCare0, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x3E_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	IMPLICIT_TYPE_DEREFERENCE(IMPLICIT_TYPE_DEREFERENCE const & other) = default;
	IMPLICIT_TYPE_DEREFERENCE(IMPLICIT_TYPE_DEREFERENCE && move) = default;

	static IMPLICIT_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
