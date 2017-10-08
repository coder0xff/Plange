// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_OP_HPP
#define INCLUDED_ASM_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_OP {
	int field_2;


	explicit ASM_OP(
		int && field_2
	) : field_2(std::move(field_2)) {}

	ASM_OP(ASM_OP const & other) = default;
	ASM_OP(ASM_OP && move) = default;

	static ASM_OP build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_OP_HPP
