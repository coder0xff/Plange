#ifndef INCLUDING_MPL_HAS_MOVE_ASSIGNMENT_HPP
#define INCLUDING_MPL_HAS_MOVE_ASSIGNMENT_HPP

#include <type_traits>

namespace mpl {
	template<typename T>
	constexpr bool has_move_assignment = std::is_move_assignable<T>::value;
}

#define INCLUDED_MPL_HAS_MOVE_ASSIGNMENT_HPP
#elif !defined(INCLUDED_MPL_HAS_MOVE_ASSIGNMENT_HPP)
#	error circular inclusion
#endif