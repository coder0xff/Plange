#ifndef INCLUDING_MPL_IS_CONST_HPP
#define INCLUDING_MPL_IS_CONST_HPP

#include <type_traits>

namespace mpl {
	template<typename T>
	constexpr bool IS_CONST = std::is_const<T>::value;
}

#define INCLUDED_MPL_IS_CONST_HPP
#elif !defined(INCLUDED_MPL_IS_CONST_HPP)
#	error circular inclusion
#endif