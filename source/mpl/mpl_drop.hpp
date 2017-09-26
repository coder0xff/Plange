#ifndef INCLUDING_MPL_DROP_HPP
#define INCLUDING_MPL_DROP_HPP

#include "mpl_list.hpp"
#include "mpl_sfinae.hpp"

namespace mpl {

	namespace details::drop {
		template<size_t Count, typename TList, typename TVoid = void>
		struct impl {
			static_assert(Count != Count, "template specialization failed");
		};

		template<template <typename...> typename TContainer, typename... Ts>
		struct impl<0, TContainer<Ts...>, void> {
			using result = TContainer<Ts...>;
		};

		template<size_t Count, template <typename...> typename TContainer, typename THead, typename... Ts>
		struct impl<Count, TContainer<THead, Ts...>, sfinae<Count >= 1, void>> {
			using result = typename impl<Count - 1, TContainer<Ts...>, void>::result;
		};
	}

	template<size_t Count, typename TList>
	using drop = typename details::drop::impl<Count, TList, void>::result;
}

#define INCLUDED_MPL_DROP_HPP
#elif !defined(INCLUDED_MPL_DROP_HPP)
#	error circular inclusion
#endif