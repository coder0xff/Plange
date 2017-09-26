// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TIME_HPP
#define INCLUDED_TIME_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct TIME {
	bool field_1;
	std::optional<std::tuple<
		int
	>> field_8;
	std::optional<std::variant<
		literal_Z_t,
		std::tuple<
			std::variant<
				literal_0x2B_t,
				literal_0x2D_t
			>,
			bool
		>
	>> field_9;


	TIME(
		bool const & field_1,
		std::optional<std::tuple<
			int
		>> const & field_8,
		std::optional<std::variant<
			literal_Z_t,
			std::tuple<
				std::variant<
					literal_0x2B_t,
					literal_0x2D_t
				>,
				bool
			>
		>> const & field_9
	) : field_1(field_1), field_8(field_8), field_9(field_9) {}

	static std::optional<TIME> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_TIME_HPP
