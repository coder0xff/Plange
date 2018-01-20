#ifndef INCLUDING_MPL_DROP_V_HPP
#define INCLUDING_MPL_DROP_V_HPP

#include "mpl_choose_v.hpp"
#include "mpl_indices.hpp"

namespace mpl {

	template<size_t Count, typename... Ts>
	constexpr auto drop_v(std::tuple<Ts...> data) {
		using all_indices = indices_of<std::tuple<Ts...>>;
		using selected_indices = drop_indices<Count, all_indices>;
		return mpl::choose_v<selected_indices>(data);
	}

	template<size_t Count, typename TElement, size_t ElementCount>
	constexpr auto drop_v(std::array<TElement, ElementCount> data) {
		using all_indices = std::make_index_sequence<ElementCount>;
		using selected_indices = drop_indices<Count, all_indices>;
		return mpl::choose_v<selected_indices>(data);
	}
}

#define INCLUDED_MPL_DROP_V_HPP
#elif !defined(INCLUDED_MPL_DROP_V_HPP)
#	error circular inclusion
#endif