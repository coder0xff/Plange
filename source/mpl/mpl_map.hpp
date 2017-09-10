#ifndef INCLUDING_MPL_MAP_HPP
#define INCLUDING_MPL_MAP_HPP

namespace mpl {

	namespace details::map {

		template<template <typename> typename TMetaFunction, typename TList>
		struct impl {
			using result = std::tuple<>;
		};

		template<template <typename> typename TMetaFunction, template<typename...> typename TContainer, typename... TTailElements>
		struct impl<TMetaFunction, TContainer<TTailElements...>> {
			using result = std::tuple<TMetaFunction<TTailElements>...>;
		};

	}

	template<template <typename> typename TMetaFunction, typename TList>
	using map = typename details::map::impl<TMetaFunction, TList>::result;

}

#define INCLUDED_MPL_MAP_HPP
#elif !defined(INCLUDED_MPL_MAP_HPP)
#	error circular inclusion
#endif