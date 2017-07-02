// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_ELEMENT_HPP
#define INCLUDED_ENUM_ELEMENT_HPP

struct EXPRESSION;
struct IC;
struct IDENTIFIER;

struct ENUM_ELEMENT {
	erased<IDENTIFIER> IDENTIFIER;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_1;
};



#endif //INCLUDED_ENUM_ELEMENT_HPP
