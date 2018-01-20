#ifndef INCLUDING_MPL_SFINAE_HPP
#define INCLUDING_MPL_SFINAE_HPP

#include <type_traits>

// SFINAE(x, y = sfinae_t) => std::enable_if<x, y>::type
#define SFINAE(...) ::mpl::sfinae<__VA_ARGS__>
// In function signature
#define SFINAE_PARAM(...) SFINAE(__VA_ARGS__) = ::mpl::sfinae_t()
// In base-type template for specialized types
#define SFINAE_TYPE_PARAM typename TSfinae = ::mpl::sfinae_t
// In template of overloaded function
#define SFINAE_OVERLOAD(...) typename = SFINAE(__VA_ARGS__) 

namespace mpl {

	struct sfinae_t {
		int operator =(int const & x) const { return x; };
	};

	template<bool Enable, typename T = sfinae_t>
	using sfinae = typename std::enable_if<Enable, T>::type;

}

#define INCLUDED_MPL_SFINAE_HPP
#elif !defined(INCLUDED_MPL_SFINAE_HPP)
#	error circular inclusion
#endif
