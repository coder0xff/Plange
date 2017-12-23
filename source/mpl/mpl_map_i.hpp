#ifndef INCLUDING_MPL_MAP_I_HPP
#define INCLUDING_MPL_MAP_I_HPP

#include "mpl_push.hpp"

namespace mpl {

	namespace detail_map_i {

		template<template <typename, int> typename TMetaFunction, int Index, typename TList>
		struct impl {
			using result = std::tuple<>;
		};

		template<template <typename, int> typename TMetaFunction, int Index, template<typename...> typename TContainer, typename THeadElement, typename... TTailElements>
		struct impl<TMetaFunction, Index, TContainer<THeadElement, TTailElements...>> {
			using result = push<TMetaFunction<THeadElement, Index>, impl<TMetaFunction, Index + 1, TContainer<TTailElements...>>>;
		};

	}

	template<template <typename> typename TMetaFunction, typename TList>
	using map = typename detail_map_i::impl<TMetaFunction, 0, TList>::result;

}

#define INCLUDED_MPL_MAP_HPP
#elif !defined(INCLUDED_MPL_MAP_HPP)
#	error circular inclusion
#endif