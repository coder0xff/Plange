#ifndef MATCH_CLASS_HPP
#define MATCH_CLASS_HPP

#include <cstdlib>

namespace parlex {

class recognizer;

struct match_class {
	recognizer const & r;
	size_t document_position;

	match_class(recognizer const & r, size_t documentPosition);
	match_class(match_class const & other) = default;
	match_class(match_class&& move) = default;

	bool operator <(match_class const & rhs) const;
};

}

#endif
