// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

typedef std::variant<
	std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>,
	std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>
> FLOOR_base;

struct FLOOR: FLOOR_base {
	static FLOOR build(parlex::details::ast_node const & n);
	explicit FLOOR(FLOOR_base const & value) : FLOOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FLOOR_HPP
