#ifndef ANY_CHARACTER_HPP
#define ANY_CHARACTER_HPP

#include <string>

#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

class any_character_t : public terminal {
public:
	any_character_t();
	~any_character_t() override = default;
	bool test(std::u32string const & document, uint32_t const documentPosition) const override final;
};

} // namespace detail
} // namespace parlex

#endif
