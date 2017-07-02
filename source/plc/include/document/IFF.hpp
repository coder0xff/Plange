// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IFF_HPP
#define INCLUDED_IFF_HPP
struct IFF {
	EXPRESSION field_1;
	std::vector<IC> field_2;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_3;
	std::vector<IC> field_4;
	EXPRESSION field_5;
};

#endif //INCLUDED_IFF_HPP