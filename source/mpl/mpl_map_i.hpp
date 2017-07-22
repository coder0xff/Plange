#ifndef INCLUDING_MPL_MAP_I_HPP
#define INCLUDING_MPL_MAP_I_HPP

#include "mpl_push.hpp"

namespace mpl {

	namespace details_map_i {

		template<template <typename, int> typename TMetaFunction, typename TList, size_t Index>
		struct impl {};

		template<template <typename, int> typename TMetaFunction, template<typename...> typename TList, typename THeadElement, typename... TTailElements, size_t Index>
		struct impl<TMetaFunction, Index, TList<THeadElement, TTailElements...>> {
			using result = push<TMetaFunction<THeadElement, Index>, impl<TMetaFunction, TList, TList<TTailElements...>, Index + 1>>;
		};

	}

	template<template <typename, int> typename TMetaFunction, typename TList>
	using map_i = typename details_map_i::impl<TMetaFunction, TList, 0>::result;

}

#define INCLUDED_MPL_MAP_I_HPP
#elif !defined(INCLUDED_MPL_MAP_I_HPP)
#	error circular inclusion
#endif