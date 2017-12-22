#ifndef INCLUDING_MPL_FOLD_HPP
#define INCLUDING_MPL_FOLD_HPP

namespace mpl {
	namespace detail::fold {
		template<template <typename, typename> typename TMetaFunction, typename TAccumulator, typename TList>
		struct impl {
			using result = TAccumulator;
		};

		template<template <typename, typename> typename TMetaFunction, typename TAccumulator, template <typename...> typename TContainer, typename THead, typename... TTail>
		struct impl <TMetaFunction, TAccumulator, TContainer<THead, TTail...>> {
			using result = typename impl<TMetaFunction, TMetaFunction<TAccumulator, THead>, TContainer<TTail...>>::result;
		};
	}

	// (Type * Type -> Type) * Type * List -> Type
	//  ^ accumulator
	//         ^ element
	//                         ^ initial accumulator
	template<template <typename, typename> typename TMetaFunction, typename TAccumulator, typename TList>
	using fold = typename detail::fold::impl<TMetaFunction, TAccumulator, TList>::result;
}

#define INCLUDED_MPL_FOLD_HPP
#elif !defined(INCLUDED_MPL_FOLD_HPP)
#	error circular inclusion
#endif