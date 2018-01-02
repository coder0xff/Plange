#ifndef MATCH_CLASS_HPP
#define MATCH_CLASS_HPP

#include <cstddef>

namespace parlex {
namespace detail {

class recognizer;

struct match_class {
	size_t document_position;
	size_t const recognizer_index;

	match_class(size_t const documentPosition, size_t const recognizerIndex);
	match_class(match_class const & other) = default;

	bool operator <(match_class const & rhs) const;
};

} // namespace detail
} // namespace parlex

#endif //MATCH_CLASS_HPP
