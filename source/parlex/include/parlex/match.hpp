#ifndef MATCH_HPP
#define MATCH_HPP

#include "match_class.hpp"
#include <set>
#include "forward_list_c.hpp"

namespace parlex {
namespace behavior2 {

class leaf;

}

struct match : match_class {
	int const consumed_character_count;
	forward_list_c<behavior2::leaf const *> leafs; //lock free for our use case

	match(struct match_class const & matchClass, int consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	match() = delete;

	bool operator <(match const & rhs) const;

	/*bool operator !=(match const & rhs) const;

	bool operator ==(match const & rhs) const;*/
};

}

#endif
