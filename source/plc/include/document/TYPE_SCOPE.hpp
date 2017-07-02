// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_HPP
#define INCLUDED_TYPE_SCOPE_HPP

struct IC;
struct TYPE_STATEMENT;

struct TYPE_SCOPE {
	std::vector<erased<IC>> field_1;
	std::vector<std::tuple<
		erased<TYPE_STATEMENT>,
		std::vector<erased<IC>>
	>> field_2;
};



#endif //INCLUDED_TYPE_SCOPE_HPP
