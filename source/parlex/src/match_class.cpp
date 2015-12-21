#include "match_class.hpp"

namespace parlex {

match_class::match_class(recognizer const & r, size_t documentPosition) : r(r), document_position(documentPosition) {}

bool match_class::operator <(match_class const & rhs) const {
	return document_position < rhs.document_position || 
		(document_position == rhs.document_position && &r < &rhs.r);
}

}