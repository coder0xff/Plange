#ifndef FAST_MATCH_HPP
#define FAST_MATCH_HPP

#include "parlex/details/match_class.hpp"

#include "forward_list_c.hpp"

namespace parlex {
namespace details {
namespace behavior {

class leaf;

}

// This is an intermediate value for creating matches which has O(1) lock-free insertion for behavior leafs.
// `match` uses a std::set, which has O(log n) insert, and would also require additional synchronization.
// By using forward_list_c, we avoid locks and slow insertions inside the parser.
struct fast_match : match_class {
	int const consumed_character_count;
	forward_list_c<behavior::leaf const *> leafs;

	fast_match(struct match_class const & matchClass, int consumedCharacterCount);
	fast_match(fast_match const & other) = default;
	fast_match(fast_match && move) = default;
	fast_match() = delete;

	bool operator <(fast_match const & rhs) const;

};


} // namespace details
} // namespace parlex

#endif //FAST_MATCH_HPP
