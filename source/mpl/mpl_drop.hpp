#ifndef INCLUDING_MPL_DROP_HPP
#define INCLUDING_MPL_DROP_HPP

#include "mpl_list.hpp"
#include "mpl_sfinae.hpp"

namespace mpl {

	namespace details::drop {
		template<size_t Count, typename TList, SFINAE_TYPE_PARAM>
		struct impl {
			static_assert(Count != Count, "template specialization failed");
		};

		template<template <typename...> typename TContainer, typename... Ts>
		struct impl<0, TContainer<Ts...>, sfinae_t> {
			using result = TContainer<Ts...>;
		};

		template<size_t Count, template <typename...> typename TContainer, typename THead, typename... Ts>
		struct impl<Count, TContainer<THead, Ts...>, SFINAE(Count >= 1)> {
			using result = typename impl<Count - 1, TContainer<Ts...>, sfinae_t>::result;
		};
	}

	template<size_t Count, typename TList>
	using drop = typename details::drop::impl<Count, TList, sfinae_t>::result;
}

#define INCLUDED_MPL_DROP_HPP
#elif !defined(INCLUDED_MPL_DROP_HPP)
#	error circular inclusion
#endif