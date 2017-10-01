#ifndef INCLUDING_MPL_DROP_V_HPP
#define INCLUDING_MPL_DROP_V_HPP

#include "mpl_choose_v.hpp"
#include "mpl_indices.hpp"

namespace mpl {

	template<size_t Count, typename... Ts>
	constexpr auto drop_v(std::tuple<Ts...> data) {
		using allIndices = indices_of<std::tuple<Ts...>>;
		using selectedIndices = drop_indices<Count, allIndices>;
		return mpl::choose_v<selectedIndices>(data);
	}

	template<size_t Count, typename TElement, size_t ElementCount>
	constexpr auto drop_v(std::array<TElement, ElementCount> data) {
		using allIndices = std::make_index_sequence<ElementCount>;
		using selectedIndices = drop_indices<Count, allIndices>;
		return mpl::choose_v<selectedIndices>(data);
	}
}

#define INCLUDED_MPL_DROP_V_HPP
#elif !defined(INCLUDED_MPL_DROP_V_HPP)
#	error circular inclusion
#endif