#ifndef INCLUDING_MPL_HEAD_HPP
#define INCLUDING_MPL_HEAD_HPP

namespace mpl {

	namespace detail::head {
		template<typename TList>
		struct impl {
			// This template should never be instantiated, so we have a static_assert that always fails
			static_assert(sizeof(TList) == -1, "template instantiation failed");
		};

		template<template<typename...> typename TContainer, typename T0, typename... Ts>
		struct impl<TContainer<T0, Ts...>> {
			using result = T0;
		};
	}

	template<typename TList>
	using head = typename detail::head::impl<TList>::result;

}

#define INCLUDED_MPL_HEAD_HPP
#elif !defined(INCLUDED_MPL_HEAD_HPP)
#	error circular inclusion
#endif