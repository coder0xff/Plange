// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_HPP
#define INCLUDED_ENUM_HPP

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
};



#endif //INCLUDED_ENUM_HPP
