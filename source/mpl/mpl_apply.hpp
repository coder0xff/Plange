#ifndef INCLUDING_MPL_APPLY_HPP
#define INCLUDING_MPL_APPLY_HPP

namespace mpl {

	namespace detail::apply {

		template<template<typename...> typename TTarget, typename TList>
		struct impl {};

		template<template<typename...> typename TTarget, template<typename...> typename TList, typename... TListElements>
		struct impl<TTarget, TList<TListElements...>> {
			using result = TTarget<TListElements...>;
		};

	}

	template<template<typename...> typename TTarget, typename TList>
	using apply = typename detail::apply::impl<TTarget, TList>::result;

}

#define INCLUDED_MPL_APPLY_HPP
#elif !defined(INCLUDED_MPL_APPLY_HPP)
#	error circular inclusion
#endif