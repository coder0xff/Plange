#include "parlex/detail/match.hpp"

#include "parlex/detail/recognizer.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

bool match::operator<(match const & rhs) const {
	if (document_position < rhs.document_position) {
		return true;
	}
	if (document_position == rhs.document_position) {
		if (consumed_character_count < rhs.consumed_character_count) {
			return true;
		}
		if (consumed_character_count == rhs.consumed_character_count) {
			return r.id < rhs.r.id;
		}
	}

	return false;

}

match::match(struct match_class const & matchClass, int const consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { throw_assert(consumedCharacterCount >= 0); }

} // namespace detail
} // namespace parlex
