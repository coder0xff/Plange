// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_HPP
#define INCLUDED_TYPE_HPP

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
};



#endif //INCLUDED_TYPE_HPP
