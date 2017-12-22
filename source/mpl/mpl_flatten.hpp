#ifndef INCLUDING_MPL_FLATTEN_HPP
#define INCLUDING_MPL_FLATTEN_HPP

#include "mpl_list.hpp"

namespace mpl {

	namespace detail::flatten {
		template<typename TAccumulator, typename TList>
		struct impl {};

		template<typename TList, template<typename...> typename UContainer>
		struct impl<TList, UContainer<>> {
			using result = TList;
		};

		template<template<typename...> typename TContainer, typename... Ts, template<typename...> typename UContainer, template<typename...> typename VContainer, typename... Vs, typename... Us>
		struct impl<TContainer<Ts...>, UContainer<VContainer<Vs...>, Us...>> {
			using result = typename impl<TContainer<Ts..., Vs...>, list<Us...>>::result;
		};
	}

	template<typename TList>
	using flatten = typename detail::flatten::impl<list<>, TList>::result;
}

#define INCLUDED_MPL_FLATTEN_HPP
#elif !defined(INCLUDED_MPL_FLATTEN_HPP)
#	error circular inclusion
#endif