#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/details/match_class.hpp"

#include <set>

namespace parlex {
namespace details {

namespace behavior {

class leaf;

}

struct match : match_class {
	size_t const consumed_character_count;

	match(struct match_class const & matchClass, int consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	match() = delete;

	bool operator <(match const & rhs) const;

};


} // namespace details
} // namespace parlex

#endif //FAST_MATCH_HPP
