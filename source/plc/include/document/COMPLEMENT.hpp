// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMPLEMENT_HPP
#define INCLUDED_COMPLEMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct COMPLEMENT {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::details::document::text<literal_0xE10xB60x9C_t> dontCare2;
	


	explicit COMPLEMENT(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::details::document::text<literal_0xE10xB60x9C_t> && dontCare2) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)) {}

	COMPLEMENT(COMPLEMENT const & other) = default;
	COMPLEMENT(COMPLEMENT && move) = default;

	static COMPLEMENT build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_COMPLEMENT_HPP
