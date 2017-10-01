#ifndef INCLUDING_MPL_SFINAE_HPP
#define INCLUDING_MPL_SFINAE_HPP

#include <type_traits>

#define SFINAE(x) sfinae<x>
#define SFINAE_PARAM(x) SFINAE(x) = sfinae_t()
#define SFINAE_TYPE_PARAM typename TSfinae = sfinae_t

namespace mpl {

	struct sfinae_t {
		int operator =(int const & x) const { return x; };
	};

	template<bool enable, typename T = sfinae_t>
	using sfinae = typename std::enable_if<enable, T>::type;

}

#define INCLUDED_MPL_SFINAE_HPP
#elif !defined(INCLUDED_MPL_SFINAE_HPP)
#	error circular inclusion
#endif
