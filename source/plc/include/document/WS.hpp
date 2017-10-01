// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WS_HPP
#define INCLUDED_WS_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct WS {
	int field_2;


	WS(
		int const & field_2
	) : field_2(field_2) {}

	static WS build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_WS_HPP
