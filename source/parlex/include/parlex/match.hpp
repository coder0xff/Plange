#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/match_class.hpp"

namespace parlex {

struct match : match_class {
	int consumed_character_count;

	match(struct match_class const & matchClass, int consumedCharacterCount);
	match() = delete;

	bool operator <(match const & rhs) const;

	/*bool operator !=(match const & rhs) const;

	bool operator ==(match const & rhs) const;*/
};

}

#endif
