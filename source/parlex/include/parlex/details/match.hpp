#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/details/match_class.hpp"

#include "forward_list_c.hpp"
#include <set>

namespace parlex {
namespace details {

struct fast_match;

namespace behavior {

class leaf;

}

struct match : match_class {
	int const consumed_character_count;
	std::set<behavior::leaf const *> leafs;

	match(struct match_class const & matchClass, int consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	explicit match(fast_match const & fastMatch);
	match() = delete;

	bool operator <(match const & rhs) const;

};


} // namespace details
} // namespace parlex

#endif //FAST_MATCH_HPP
