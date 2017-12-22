#ifndef INCLUDING_MPL_INDICES_HPP
#define INCLUDING_MPL_INDICES_HPP

#include <type_traits>
#include <tuple>

#include "mpl_sfinae.hpp"
#include "mpl_utils.hpp"

namespace mpl {

	template<size_t... Offsets>
	using indices = std::index_sequence<Offsets...>;

	namespace detail::indices {

		template<typename TList>
		struct indices_of_impl {};

		template<template<typename...> typename TContainer, typename... Ts>
		struct indices_of_impl<TContainer<Ts...>> {
			using result = decltype(std::make_index_sequence<sizeof...(Ts)>{});
		};

		template<size_t... Ints>
		constexpr auto drop_indices_impl(std::integral_constant<size_t, 0>, std::index_sequence<Ints...>) {
			return std::index_sequence<Ints...>();
		}

		template<size_t Count, size_t HeadInt, size_t... TailInts>
		constexpr auto drop_indices_impl(std::integral_constant<size_t, Count>, std::index_sequence<HeadInt, TailInts...>, SFINAE_PARAM(Count != 0)) {
			return drop_indices_impl(std::integral_constant<size_t, Count - 1>(), std::index_sequence<TailInts...>());
		}

		template<typename TRawIndices>
		struct apply_impl {};

		template<size_t... Offsets>
		struct apply_impl<std::index_sequence<Offsets...>> {
			template<typename TFunctor>
			static constexpr auto invoke(TFunctor && functor) {
				return functor(Offsets...);
			}
		};
	}

	template<typename TTuple>
	using indices_of = typename detail::indices::indices_of_impl<TTuple>::result;

	template<size_t Count, typename TIndices>
	using drop_indices = decltype(detail::indices::drop_indices_impl(std::integral_constant<size_t, Count>(), TIndices()));

	template<typename TIndices, typename TFunctor>
	constexpr auto apply_indices(TFunctor && functor) {
		return detail::indices::apply_impl<TIndices>::invoke(functor);
	}
}

#define INCLUDED_MPL_INDICES_HPP
#elif !defined(INCLUDED_MPL_INDICES_HPP)
#	error circular inclusion
#endif