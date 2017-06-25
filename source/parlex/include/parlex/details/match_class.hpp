#ifndef MATCH_CLASS_HPP
#define MATCH_CLASS_HPP

#include <cstddef>

namespace parlex {
namespace details {

class recognizer;

struct match_class {
	recognizer const & r;
	size_t document_position;

	match_class(recognizer const & r, size_t documentPosition);
	match_class(match_class const & other) = default;

	bool operator <(match_class const & rhs) const;
};

} // namespace details
} // namespace parlex

#endif //MATCH_CLASS_HPP