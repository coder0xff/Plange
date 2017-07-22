// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OBJECT_HPP
#define INCLUDED_OBJECT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;
struct INHERITANCE_LIST;
struct TYPE_SCOPE;

struct OBJECT {
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

	OBJECT(
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
};



#endif //INCLUDED_OBJECT_HPP
