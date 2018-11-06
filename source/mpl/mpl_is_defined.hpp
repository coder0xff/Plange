#ifndef INCLUDING_MPL_IS_DEFINED
#define INCLUDING_MPL_IS_DEFINED
#include <type_traits>

namespace mpl {
	namespace detail::is_defined {
		template <class, class = void>
		struct is_defined_impl : std::false_type { };

		template <class T>
		struct is_defined_impl<T, typename std::enable_if<sizeof(T) - sizeof(T) == 0>::type> : std::true_type {};
	}

	template <typename T>
	constexpr bool is_defined = detail::is_defined::is_defined_impl<T>::value;
}

#define INCLUDED_MPL_IS_DEFINED
#elif !defined(INCLUDED_MPL_IS_DEFINED)
#	error circular inclusion
#endif
