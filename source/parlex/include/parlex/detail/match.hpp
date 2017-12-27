#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/detail/match_class.hpp"

namespace parlex {
namespace detail {

struct match : match_class {
	size_t const consumed_character_count;

	match(struct match_class const & matchClass, int consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	match() = delete;

	bool operator <(match const & rhs) const;
};


} // namespace detail
} // namespace parlex

#endif //FAST_MATCH_HPP
