// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
#define INCLUDED_INHERITANCE_ITEM_PREFIX_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ICR;
struct VISIBILITY_MODIFIER;

struct INHERITANCE_ITEM_PREFIX {
	std::variant<
		erased<VISIBILITY_MODIFIER>,
		std::tuple<
			erased<VISIBILITY_MODIFIER>,
			erased<ICR>
		>,
		struct diamond {}
	> field_1;
	erased<ICR> field_2;

	INHERITANCE_ITEM_PREFIX(
		std::variant<
			erased<VISIBILITY_MODIFIER>,
			std::tuple<
				erased<VISIBILITY_MODIFIER>,
				erased<ICR>
			>,
			struct diamond {}
		> const & field_1,
		erased<ICR> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
