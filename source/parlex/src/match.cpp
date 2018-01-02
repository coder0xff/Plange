#include "parlex/detail/match.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

match::match(size_t documentPosition, size_t recognizerIndex, size_t const consumedCharacterCount) : match_class(documentPosition, recognizerIndex), consumed_character_count(consumedCharacterCount) {}
match::match(struct match_class const & matchClass, size_t const consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { }

match & match::operator=(match && move) noexcept {
	this->~match();
	new (this) match(std::move(move));
	return *this;
}

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
