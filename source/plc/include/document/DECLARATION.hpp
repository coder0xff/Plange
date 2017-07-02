// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DECLARATION_HPP
#define INCLUDED_DECLARATION_HPP

struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DECLARATION {
	erased<IDENTIFIER> IDENTIFIER;
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
};



#endif //INCLUDED_DECLARATION_HPP
