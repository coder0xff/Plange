#ifndef INCLUDING_MPL_FOLD_I_HPP
#define INCLUDING_MPL_FOLD_I_HPP

#include <tuple>

namespace mpl {
	namespace details::fold_i {
		template<template <typename, size_t, typename> typename TMetaFunction, size_t Index, typename TAccumulator, typename TList>
		struct impl {
			using result = TAccumulator;
		};

		template<template <typename, size_t, typename> typename TMetaFunction, size_t Index, typename TAccumulator, template <typename...> typename TContainer, typename THead, typename... TTail>
		struct impl <TMetaFunction, Index, TAccumulator, TContainer<THead, TTail...>> {
			using result = typename impl<TMetaFunction, Index + 1, TMetaFunction<TAccumulator, Index, THead>, std::tuple<TTail...>>::result;
		};
	}

	// (Type * Type -> Type) * Type * List -> Type
	template<template <typename, size_t, typename> typename TMetaFunction, typename TAccumulator, typename TList>
	using fold_i = typename details::fold_i::impl<TMetaFunction, 0, TAccumulator, TList>::result;
}

#define INCLUDED_MPL_FOLD_I_HPP
#elif !defined(INCLUDED_MPL_FOLD_I_HPP)
#	error circular inclusion
#endif