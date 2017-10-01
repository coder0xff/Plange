// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONTINUE_HPP
#define INCLUDED_CONTINUE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct ICR;
struct IDENTIFIER;

struct CONTINUE {
	std::optional<std::variant<
		std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>,
			std::vector<erased<IC>>
		>,
		std::tuple<
			std::vector<erased<ICR>>,
			erased<IDENTIFIER>
		>
	>> field_1;


	CONTINUE(
		std::optional<std::variant<
			std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<EXPRESSION>,
				std::vector<erased<IC>>
			>,
			std::tuple<
				std::vector<erased<ICR>>,
				erased<IDENTIFIER>
			>
		>> const & field_1
	) : field_1(field_1) {}

	static CONTINUE build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CONTINUE_HPP
