// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DOWNCASTS_HPP
#define INCLUDED_DOWNCASTS_HPP

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

struct DOWNCASTS {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_downcasts_t> dontCare2;
	
	std::vector<erased<IC>> field_3;
	
	erased<EXPRESSION> field_4;
	


	explicit DOWNCASTS(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_downcasts_t> && dontCare2, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	DOWNCASTS(DOWNCASTS const & other) = default;
	DOWNCASTS(DOWNCASTS && move) = default;

	static DOWNCASTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DOWNCASTS_HPP
