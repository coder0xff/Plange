#ifndef INCLUDING_MPL_EQUALS_HPP
#define INCLUDING_MPL_EQUALS_HPP
#include <type_traits>

namespace mpl {
	template<typename TLeft, typename TRight>
	constexpr bool equals = std::is_same<TLeft, TRight>::value;
}

#define INCLUDED_MPL_EQUALS_HPP
#elif !defined(INCLUDED_MPL_EQUALS_HPP)
#	error circular inclusion
#endif