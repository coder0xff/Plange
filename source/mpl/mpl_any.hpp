#ifndef INCLUDING_MPL_ANY_HPP
#define INCLUDING_MPL_ANY_HPP

#include "mpl_list.hpp"

namespace mpl {

	namespace detail::any {
		template<template<typename> typename TMetaPredicate, typename TList>
		struct impl {};

		template<template<typename> typename TMetaPredicate, template<typename...> typename TContainer, typename T0>
		struct impl<TMetaPredicate, TContainer<T0>> {
			static constexpr bool result = TMetaPredicate<T0>::result;
		};

		template<template<typename> typename TMetaPredicate, template<typename...> typename TContainer, typename T0, typename... Ts>
		struct impl<TMetaPredicate, TContainer<T0, Ts...>> {
			static constexpr bool result = TMetaPredicate<T0>::result || impl<TMetaPredicate, list<Ts...>>::result;
		};

	}

	template<template<typename> typename TMetaPredicate, typename TList>
	constexpr bool any = detail::any::impl<TMetaPredicate, TList>::result;

	template<template<typename> typename TMetaPredicate, typename TList>
	struct any_f {
		static constexpr bool result = any<TMetaPredicate, TList>;
	};
}

#define INCLUDED_MPL_ANY_HPP
#elif !defined(INCLUDED_MPL_ANY_HPP)
#	error circular inclusion
#endif