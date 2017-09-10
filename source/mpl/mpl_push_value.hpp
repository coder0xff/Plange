#ifndef INCLUDING_MPL_PUSH_VALUE_HPP
#define INCLUDING_MPL_PUSH_VALUE_HPP

#include <tuple>

#include "mpl_utils.hpp"

namespace mpl {
	namespace details_push_value {

		template<typename TListHead, typename TListTail, size_t... Indices>
		auto impl(TListHead && element, TListTail list, std::index_sequence<Indices...>) {
			return make_tuple(std::forward<TListHead>(element), std::get<Indices>(std::forward<TListTail>(list))...);
		}

	}

	template<typename THead, typename... TTailElements>
	std::tuple<THead, TTailElements...> impl(THead && element, std::tuple<TTailElements...> list) {
		return impl(
			std::forward<THead>(element),
			std::forward<std::tuple<TTailElements...>>(list),
			details::sequence(std::forward<std::tuple<TTailElements...>>(list))
		);

	}

}

#define INCLUDED_MPL_PUSH_VALUE_HPP
#elif !defined(INCLUDED_MPL_PUSH_VALUE_HPP)
#	error circular inclusion
#endif