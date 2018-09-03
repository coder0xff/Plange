#ifndef INCLUDED_PARLEX_MATCH_HPP
#define INCLUDED_PARLEX_MATCH_HPP

#include "parlex/detail/match_class.hpp"

namespace parlex {
namespace detail {

struct match : match_class {
	uint32_t consumed_character_count;

	match(uint32_t const documentPosition, uint16_t const recognizerIndex, uint32_t const consumedCharacterCount);
	match(match_class const & matchClass, uint32_t const consumedCharacterCount);

	bool operator <(match const & rhs) const;
};


} // namespace detail
} // namespace parlex

#endif // INCLUDED_PARLEX_MATCH_HPP
