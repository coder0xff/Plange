#ifndef INCLUDING_MPL_APPLY_VALUES_HPP
#define INCLUDING_MPL_APPLY_VALUES_HPP

#include <utility>

#include "mpl_utils.hpp"

namespace mpl {

	namespace details_apply_values {

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

	}

	template<typename TFunctor, typename TTuple>
	constexpr auto apply_values(TFunctor && functor, TTuple && elements) {
		return impl(
			std::forward<TFunctor>(functor),
			std::forward<TTuple>(elements),
			details::sequence(std::forward<TTuple>(elements))
		);
	}

}

#define INCLUDED_MPL_APPLY_VALUE_HPP
#elif !defined(INCLUDED_MPL_APPLY_VALUE_HPP)
#	error circular inclusion
#endif