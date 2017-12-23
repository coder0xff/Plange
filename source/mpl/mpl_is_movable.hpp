#ifndef INCLUDING_MPL_IS_MOVABLE_HPP
#define INCLUDING_MPL_IS_MOVABLE_HPP

#include <type_traits>

namespace mpl {
	template<typename T>
	constexpr bool IS_MOVABLE = std::is_move_constructible<T>::value;
}

#define INCLUDED_MPL_IS_MOVABLE_HPP
#elif !defined(INCLUDED_MPL_IS_MOVABLE_HPP)
#	error circular inclusion
#endif