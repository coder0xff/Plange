#ifndef INCLUDING_MPL_SFINAE_HPP
#define INCLUDING_MPL_SFINAE_HPP

#include <type_traits>

namespace mpl {

	template<bool enable, typename T>
	using sfinae = typename std::enable_if<enable, T>::type;

}

#define INCLUDED_MPL_SFINAE_HPP
#elif !defined(INCLUDED_MPL_SFINAE_HPP)
#	error circular inclusion
#endif
