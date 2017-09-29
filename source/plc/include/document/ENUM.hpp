// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_HPP
#define INCLUDED_ENUM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ENUM_ELEMENT;
struct IC;
struct INHERITANCE_LIST;

struct ENUM {
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
	std::optional<std::tuple<
		erased<ENUM_ELEMENT>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<ENUM_ELEMENT>
		>>
	>> field_4;


	ENUM(
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
		std::optional<std::tuple<
			erased<ENUM_ELEMENT>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<ENUM_ELEMENT>
			>>
		>> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static std::optional<ENUM> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_ENUM_HPP
