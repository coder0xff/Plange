#ifndef INCLUDING_MPL_IS_COPYABLE_HPP
#define INCLUDING_MPL_IS_COPYABLE_HPP

#include <type_traits>

namespace mpl {
	template<typename T>
	constexpr bool is_copyable = std::is_copy_constructible<T>::value;
}

#define INCLUDED_MPL_IS_COPYABLE_HPP
#elif !defined(INCLUDED_MPL_IS_COPYABLE_HPP)
#	error circular inclusion
#endif