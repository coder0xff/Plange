// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_HPP
#define INCLUDED_TYPE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct INHERITANCE_LIST;
struct TYPE_SCOPE;

struct TYPE {
	std::vector<erased<IC>> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<INHERITANCE_LIST>,
		std::vector<erased<IC>>
	>> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<INHERITANCE_LIST>,
		std::vector<erased<IC>>
	>> field_3;
	erased<TYPE_SCOPE> field_4;


	TYPE(
		std::vector<erased<IC>> const & field_1,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<INHERITANCE_LIST>,
			std::vector<erased<IC>>
		>> const & field_2,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<INHERITANCE_LIST>,
			std::vector<erased<IC>>
		>> const & field_3,
		erased<TYPE_SCOPE> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static TYPE build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_HPP
