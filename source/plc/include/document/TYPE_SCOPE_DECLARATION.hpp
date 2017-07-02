// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_DECLARATION_HPP
#define INCLUDED_TYPE_SCOPE_DECLARATION_HPP

struct IC;
struct IDENTIFIER;
struct MEMBER_OFFSET;
struct XML_DOC_STRING;

struct TYPE_SCOPE_DECLARATION {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<MEMBER_OFFSET>
	>> field_3;
};



#endif //INCLUDED_TYPE_SCOPE_DECLARATION_HPP
