#ifndef INCLUDED_PARLEX_MATCH_CLASS_HPP
#define INCLUDED_PARLEX_MATCH_CLASS_HPP

#include <cstdint>

namespace parlex {
namespace detail {

class recognizer;

struct match_class {
	uint32_t document_position;
	uint16_t recognizer_index;

	match_class(uint32_t const documentPosition, uint16_t const recognizerIndex);

	bool operator <(match_class const & rhs) const;
};

} // namespace detail
} // namespace parlex

#endif // INCLUDED_PARLEX_MATCH_CLASS_HPP
