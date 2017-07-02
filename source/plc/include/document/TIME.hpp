// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TIME_HPP
#define INCLUDED_TIME_HPP
struct TIME {
	bool field_1;
	decimal_digit field_2;
	decimal_digit field_3;
	decimal_digit field_4;
	decimal_digit field_5;
	decimal_digit field_6;
	decimal_digit field_7;
	std::optional<std::tuple<
		decimal_digit,
		std::vector<decimal_digit>
	>> field_8;
	std::optional<std::variant<
		std::std::integral_constant<int, 0>,
		std::tuple<
			std::variant<
				std::std::integral_constant<int, 0>,
				std::std::integral_constant<int, 1>
			>,
			decimal_digit,
			decimal_digit,
			std::optional<std::tuple<
				decimal_digit,
				decimal_digit
			>>
		>
	>> field_9;
};

#endif //INCLUDED_TIME_HPP