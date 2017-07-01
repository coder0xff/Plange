#include "parlex/details/match.hpp"

#include "parlex/details/fast_match.hpp"
#include "parlex/details/recognizer.hpp"

#include "utils.hpp"

namespace parlex {
namespace details {

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

match::match(struct match_class const & matchClass, int consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { throw_assert(consumedCharacterCount >= 0); }

match::match(fast_match const & fastMatch) : match_class(fastMatch), consumed_character_count(fastMatch.consumed_character_count) {
	// range based std::set constructor doesn't seem to like the forward_list_c iterators and doesn't compile in VC++ 2017.
	for (auto const & leafPtr : fastMatch.leafs) {
		leafs.insert(leafPtr);
	}
}

} // namespace details
} // namespace parlex
