#include "parlex/match.hpp"

namespace parlex {

bool match::operator<(match const & rhs) const
{
	return consumed_character_count < rhs.consumed_character_count ||
		(consumed_character_count == rhs.consumed_character_count && (match_class)*this < (match_class)rhs);
}

bool match::operator!=(match const & rhs) const
{
	return *this < rhs || rhs < *this;
}

bool match::operator==(match const & rhs) const
{
	return !(*this != rhs);
}

match::match(struct match_class const & matchClass, int consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { }

}