#include "parlex/match_class.hpp"

namespace parlex {

match_class::match_class(recognizer const & r, size_t documentPosition) : r(r), documentPosition(documentPosition) {}

bool match_class::operator <(match_class const & rhs) const {
	return documentPosition < rhs.documentPosition || 
		(documentPosition == rhs.documentPosition && &r < &rhs.r);
}

}