#ifndef MATCH_CLASS_HPP
#define MATCH_CLASS_HPP

#include <cstdint>

namespace parlex {
namespace detail {

class recognizer;

struct match_class {
	uint32_t document_position;
	uint16_t const recognizer_index;

	match_class(uint32_t const documentPosition, uint16_t const recognizerIndex);
	match_class(match_class const & other) = default;

	bool operator <(match_class const & rhs) const;
};

} // namespace detail
} // namespace parlex

#endif //MATCH_CLASS_HPP
