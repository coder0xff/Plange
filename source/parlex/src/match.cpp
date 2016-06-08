#include <cassert>

#include "parlex/match.hpp"
#include "parlex/recognizer.hpp"

namespace parlex {

bool match::operator<(match const & rhs) const
{
	return document_position < rhs.document_position || 
		(document_position == rhs.document_position && (consumed_character_count < rhs.consumed_character_count ||
		(consumed_character_count == rhs.consumed_character_count && r.get_id() < rhs.r.get_id())));
}

bool match::operator!=(match const & rhs) const
{
	return *this < rhs || rhs < *this;
}

bool match::operator==(match const & rhs) const
{
	return !(*this != rhs);
}

match::match(struct match_class const & matchClass, int consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { assert(consumedCharacterCount >= 0); }

}