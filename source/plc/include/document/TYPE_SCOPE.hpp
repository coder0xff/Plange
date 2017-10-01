// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_HPP
#define INCLUDED_TYPE_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct TYPE_STATEMENT;

struct TYPE_SCOPE {
	std::vector<erased<IC>> field_1;
	std::vector<std::tuple<
		erased<TYPE_STATEMENT>,
		std::vector<erased<IC>>
	>> field_2;


	TYPE_SCOPE(
		std::vector<erased<IC>> const & field_1,
		std::vector<std::tuple<
			erased<TYPE_STATEMENT>,
			std::vector<erased<IC>>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static TYPE_SCOPE build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_HPP
