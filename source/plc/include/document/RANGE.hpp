// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RANGE_HPP
#define INCLUDED_RANGE_HPP

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
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::variant<
			literal_0x5D_t,
			literal_0x29_t
		>
	>,
	std::tuple<
		std::variant<
			literal_0x5B_t,
			literal_0x28_t
		>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::vector<erased<IC>>
	>,
	std::tuple<
		std::variant<
			literal_0x28_t,
			literal_0x5B_t
		>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::variant<
			literal_0x5D_t,
			literal_0x29_t
		>
	>
> RANGE_base;

struct RANGE: RANGE_base {
	static RANGE build(parlex::details::ast_node const & n);
	explicit RANGE(RANGE_base const & value) : RANGE_base(value) {}
};
} // namespace plc



#endif //INCLUDED_RANGE_HPP
