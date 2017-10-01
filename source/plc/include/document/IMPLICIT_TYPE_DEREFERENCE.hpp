// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;

struct IMPLICIT_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;


	IMPLICIT_TYPE_DEREFERENCE(
		std::vector<erased<IC>> const & field_1
	) : field_1(field_1) {}

	static IMPLICIT_TYPE_DEREFERENCE build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
