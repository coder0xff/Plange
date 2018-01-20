#ifndef INCLUDING_MPL_APPLY_V_HPP
#define INCLUDING_MPL_APPLY_V_HPP

#include <utility>

#include "mpl_indices.hpp"

namespace mpl {

	namespace detail::apply_values {

		template <typename TFunctor, typename TTuple, size_t... Indices>
		constexpr auto impl(TFunctor const & functor, TTuple && t, std::index_sequence<Indices...>)
		{
			return functor(std::get<Indices>(std::forward<TTuple>(t))...);
		}

		template <typename TFunctor, typename TTuple, size_t... Indices>
		constexpr auto impl(TFunctor & functor, TTuple && t, std::index_sequence<Indices...>)
		{
		 	return functor(std::get<Indices>(std::forward<TTuple>(t))...);
		}

		template <typename T, typename TTuple, size_t... Indices>
		constexpr auto impl_ctor(TTuple && t, std::index_sequence<Indices...>) {
			return T(std::get<Indices>(std::forward<TTuple>(t))...);
		}
	}

	template<typename TFunctor, typename TTuple>
	constexpr auto apply_v(TFunctor && functor, TTuple && elements) {
		return impl(
			std::forward<TFunctor>(functor),
			std::forward<TTuple>(elements),
			indices_of<TTuple>()
		);
	}

	template<typename T, typename TTuple>
	constexpr auto apply_v_constructor(TTuple && elements) {		
		return detail::apply_values::impl_ctor<T>(
			std::forward<TTuple>(elements),
			indices_of<TTuple>()
		);
	}
}

#define INCLUDED_MPL_APPLY_VALUES_HPP
#elif !defined(INCLUDED_MPL_APPLY_VALUES_HPP)
#	error circular inclusion
#endif