#ifndef INCLUDING_MPL_PUSH_V_HPP
#define INCLUDING_MPL_PUSH_V_HPP

#include <tuple>

namespace mpl {
	namespace detail::push_v {

		template<typename TListHead, typename TListTail, size_t... Indices>
		auto impl(TListHead && element, TListTail list, std::index_sequence<Indices...>) {
			return make_tuple(std::forward<TListHead>(element), std::get<Indices>(std::forward<TListTail>(list))...);
		}

	}

	template<typename THead, typename... TTailElements>
	constexpr std::tuple<THead, TTailElements...> push_v(THead && element, std::tuple<TTailElements...> list) {
		return impl(
			std::forward<THead>(element),
			std::forward<std::tuple<TTailElements...>>(list),
			detail::push_v::impl(std::forward<std::tuple<TTailElements...>>(list))
		);
	}

}

#define INCLUDED_MPL_PUSH_V_HPP
#elif !defined(INCLUDED_MPL_PUSH_VALUE_HPP)
#	error circular inclusion
#endif