#include "parlex/match.hpp"

#include "parlex/recognizer.hpp"

#include "utils.hpp"

namespace parlex {

bool match::operator<(match const & rhs) const {
	if (document_position < rhs.document_position) {
		return true;
	} else if (document_position == rhs.document_position) {
		if (consumed_character_count < rhs.consumed_character_count) {
			return true;
		} else if (consumed_character_count == rhs.consumed_character_count) {
			return r.id < rhs.r.id;
		}
	}

	return false;

}

match::match(struct match_class const & matchClass, int consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { throw_assert(consumedCharacterCount >= 0); }

}
