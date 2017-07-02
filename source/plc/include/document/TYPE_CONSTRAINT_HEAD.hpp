// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_HEAD_HPP
#define INCLUDED_TYPE_CONSTRAINT_HEAD_HPP
struct TYPE_CONSTRAINT_HEAD {
	std::optional<std::tuple<
		XML_DOC_STRING,
		std::vector<IC>
	>> field_1;
	std::vector<std::tuple<
		ATTRIBUTE,
		std::vector<IC>
	>> field_2;
	std::optional<std::tuple<
		VISIBILITY_MODIFIER,
		std::vector<IC>
	>> field_3;
	std::optional<std::tuple<
		std::vector<IC>
	>> field_4;
	std::optional<std::tuple<
		std::vector<IC>
	>> field_5;
	std::variant<
		TYPE_DEREFERENCE,
		VOLATILE_TYPE_DEREFERENCE,
		IMPLICIT_TYPE_DEREFERENCE,
		VOLATILE_IMPLICIT_TYPE_DEREFERENCE
	> type_dereference;
};

#endif //INCLUDED_TYPE_CONSTRAINT_HEAD_HPP