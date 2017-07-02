// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DEFINITION_HPP
#define INCLUDED_DEFINITION_HPP

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DEFINITION {
	erased<EXPRESSION> EXPRESSION;
	erased<IDENTIFIER> IDENTIFIER;
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
};



#endif //INCLUDED_DEFINITION_HPP
