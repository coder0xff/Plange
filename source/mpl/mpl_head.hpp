#ifndef INCLUDING_MPL_HEAD_HPP
#define INCLUDING_MPL_HEAD_HPP

namespace mpl {

	namespace details::head {
		template<typename TList>
		struct impl {
			static_assert(!std::is_same_v<TList, TList>, "template instantiation failed");
		};

		template<template<typename...> typename TContainer, typename T0, typename... Ts>
		struct impl<TContainer<T0, Ts...>> {
			using result = T0;
		};
	}

	template<typename TList>
	using head = typename details::head::impl<TList>::result;

}

#define INCLUDED_MPL_HEAD_HPP
#elif !defined(INCLUDED_MPL_HEAD_HPP)
#	error circular inclusion
#endif