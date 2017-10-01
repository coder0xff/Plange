// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ICR_HPP
#define INCLUDED_ICR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;

struct ICR {
	erased<IC> field_1;
	std::vector<erased<IC>> field_2;


	ICR(
		erased<IC> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static ICR build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ICR_HPP
