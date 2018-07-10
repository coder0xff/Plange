#ifndef INCLUDING_MPL_EQUALS_HPP
#define INCLUDING_MPL_EQUALS_HPP

#include <type_traits>

namespace mpl {
	template<typename TLeft, typename TRight>
	constexpr bool EQUALS = std::is_same<TLeft, TRight>::value;

	template<typename TLeft, typename TRight>
	struct equals_f {
		static constexpr bool result = EQUALS<TLeft, TRight>;
	};
}

#define INCLUDED_MPL_EQUALS_HPP
#elif !defined(INCLUDED_MPL_EQUALS_HPP)
#	error circular inclusion
#endif