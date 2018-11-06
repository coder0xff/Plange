#include "parlex/detail/match.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

match::match(uint32_t documentPosition, uint16_t recognizerIndex, uint32_t const consumedCharacterCount) : match_class(documentPosition, recognizerIndex), consumed_character_count(consumedCharacterCount) {}
match::match(struct match_class const & matchClass, uint32_t const consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { }

bool match::operator<(match const & rhs) const {
	if (this->match_class::operator<(rhs)) {
		return true;
	}
	if (rhs.match_class::operator<(*this)) {
		return false;
	}
	return consumed_character_count < rhs.consumed_character_count;
}

} // namespace detail
} // namespace parlex
