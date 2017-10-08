// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_HEX_HPP
#define INCLUDED_HEX_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct HEX {
	int field_2;


	explicit HEX(
		int && field_2
	) : field_2(std::move(field_2)) {}

	HEX(HEX const & other) = default;
	HEX(HEX && move) = default;

	static HEX build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_HEX_HPP
