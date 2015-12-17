#ifndef MATCH_CLASS_HPP
#define MATCH_CLASS_HPP

namespace parlex {

class recognizer;

struct match_class {
	recognizer const & r;
	int document_position;

	match_class(recognizer const & r, int documentPosition);
	match_class(match_class const & other) = default;
	match_class(match_class&& move) = default;

	bool operator <(match_class const & rhs) const;
};

}

#endif