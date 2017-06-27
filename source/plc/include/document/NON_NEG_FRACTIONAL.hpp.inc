// This file was generated using parlex's cpp_generator

typedef std::variant<
	std::tuple<
		decimal_digit,
		std::vector<decimal_digit>,
		std::vector<decimal_digit>
	>,
	std::tuple<
		decimal_digit,
		std::vector<decimal_digit>
	>
> NON_NEG_FRACTIONAL;