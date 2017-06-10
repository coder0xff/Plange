#include "parlex/match.hpp"

#include "utils.hpp"
#include "parlex/recognizer.hpp"

namespace parlex {

bool match::operator<(match const & rhs) const
{
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

/*return		document_position < rhs.document_position ||
		(document_position == rhs.document_position && (consumed_character_count < rhs.consumed_character_count ||
		(consumed_character_count == rhs.consumed_character_count && r.id < rhs.r.id)));*/
}

/*bool match::operator!=(match const & rhs) const
{
	return *this < rhs || rhs < *this;
}

bool match::operator==(match const & rhs) const
{
	return !(*this != rhs);
}*/

match::match(struct match_class const & matchClass, int consumedCharacterCount) : match_class(matchClass), consumed_character_count(consumedCharacterCount) { throw_assert(consumedCharacterCount >= 0); }

}