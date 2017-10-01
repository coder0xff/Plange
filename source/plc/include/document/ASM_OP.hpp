// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_OP_HPP
#define INCLUDED_ASM_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASM_OP {
	int field_2;


	ASM_OP(
		int const & field_2
	) : field_2(field_2) {}

	static ASM_OP build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_OP_HPP
