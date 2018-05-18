#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/detail/match_class.hpp"

namespace parlex {
namespace detail {

struct match : match_class {
	uint32_t const consumed_character_count;

	match() = delete;
	match(uint32_t const documentPosition, uint16_t const recognizerIndex, uint32_t const consumedCharacterCount);
	match(match_class const & matchClass, uint32_t const consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	match & operator =(match && move) noexcept;

	bool operator <(match const & rhs) const;
};


} // namespace detail
} // namespace parlex

#endif //FAST_MATCH_HPP
