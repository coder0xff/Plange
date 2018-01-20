#include "parlex/detail/match_class.hpp"

namespace parlex {
namespace detail {

match_class::match_class(uint32_t const documentPosition, uint16_t const recognizerIndex) : document_position(documentPosition), recognizer_index(recognizerIndex) {
}

bool match_class::operator <(match_class const & rhs) const {
	return document_position < rhs.document_position ||
		(document_position == rhs.document_position && recognizer_index < rhs.recognizer_index);
}

} // namespace detail
} // namespace parlex
