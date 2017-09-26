// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STRING_HPP
#define INCLUDED_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

typedef std::string STRING_base;

struct STRING: STRING_base {
	static std::optional<STRING> build(std::vector<parlex::details::match>::iterator & i);
	explicit STRING(STRING_base const & value) : STRING_base(value) {}
};
} // namespace plc



#endif //INCLUDED_STRING_HPP
