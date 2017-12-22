// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ICR_HPP
#define INCLUDED_ICR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;

struct ICR {
	erased<IC> field_1;
	
	std::vector<erased<IC>> field_2;
	


	explicit ICR(
		erased<IC> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ICR(ICR const & other) = default;
	ICR(ICR && move) = default;

	static ICR build(parlex::detail::ast_node const & n);
	static parlex::detail::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_ICR_HPP
