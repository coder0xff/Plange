#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/details/match_class.hpp"

#include "forward_list_c.hpp"

namespace parlex {
namespace details {
namespace behavior {

class leaf;

}

struct match : match_class {
	int const consumed_character_count;
	forward_list_c<behavior::leaf const *> leafs; //lock free for our use case

	match(struct match_class const & matchClass, int consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	match() = delete;

	bool operator <(match const & rhs) const;

};


} // namespace details
} // namespace parlex

#endif //MATCH_HPP
