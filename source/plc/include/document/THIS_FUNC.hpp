// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THIS_FUNC_HPP
#define INCLUDED_THIS_FUNC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct THIS_FUNC {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>> field_1;


	THIS_FUNC(
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>,
			std::vector<erased<IC>>
		>> const & field_1
	) : field_1(field_1) {}

	static THIS_FUNC build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_THIS_FUNC_HPP
