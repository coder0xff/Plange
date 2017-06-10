#ifndef MATCH_HPP
#define MATCH_HPP

#include "match_class.hpp"

namespace parlex {

struct match : match_class {
	int consumed_character_count;

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
