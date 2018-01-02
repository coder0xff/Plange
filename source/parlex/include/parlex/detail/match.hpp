#ifndef MATCH_HPP
#define MATCH_HPP

#include "parlex/detail/match_class.hpp"

namespace parlex {
namespace detail {

struct match : match_class {
	size_t const consumed_character_count;

	match() = delete;
	match(size_t const documentPosition, size_t const recognizerIndex, size_t const consumedCharacterCount);
	match(match_class const & matchClass, size_t const consumedCharacterCount);
	match(match const & other) = default;
	match(match && move) = default;
	match & operator =(match && move) noexcept;

	bool operator <(match const & rhs) const;
};


} // namespace detail
} // namespace parlex

#endif //FAST_MATCH_HPP
