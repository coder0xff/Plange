// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WS_HPP
#define INCLUDED_WS_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct WS {
	int field_2;


	explicit WS(
		int && field_2
	) : field_2(std::move(field_2)) {}

	WS(WS const & other) = default;
	WS(WS && move) = default;

	static WS build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_WS_HPP
