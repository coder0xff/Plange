// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_HEAD_HPP
#define INCLUDED_TYPE_CONSTRAINT_HEAD_HPP

struct ATTRIBUTE;
struct IC;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;
struct VISIBILITY_MODIFIER;
struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
struct VOLATILE_TYPE_DEREFERENCE;
struct XML_DOC_STRING;

struct TYPE_CONSTRAINT_HEAD {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	std::vector<std::tuple<
		erased<ATTRIBUTE>,
		std::vector<erased<IC>>
	>> field_2;
	std::optional<std::tuple<
		erased<VISIBILITY_MODIFIER>,
		std::vector<erased<IC>>
	>> field_3;
	std::optional<std::tuple<
		std::vector<erased<IC>>
	>> field_4;
	std::optional<std::tuple<
		std::vector<erased<IC>>
	>> field_5;
	std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<VOLATILE_TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>,
		erased<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	> type_dereference;
};



#endif //INCLUDED_TYPE_CONSTRAINT_HEAD_HPP
