#ifndef INCLUDING_MPL_CHOOSE_V_HPP
#define INCLUDING_MPL_CHOOSE_V_HPP

#include <type_traits>
#include <tuple>
#include "mpl_utils.hpp"

// given a index_sequence and a tuple, create a new tuple with only the chosen elements

namespace mpl {
	
	namespace details::choose_v {
		template<typename IndexSequenceT>
		struct impl {};

		template<size_t... Indices>
		struct impl<std::index_sequence<Indices...>> {
			template<typename... Ts>
			constexpr static auto f(std::tuple<Ts...> data) {
				return std::make_tuple(std::get<Indices>(data)...);
			}

			template<typename T, size_t DataSize>
			constexpr static auto f(std::array<T, DataSize> data) {
				return std::make_array<T>(std::get<Indices>(data)...);
			}
		};
	}

	template<typename IndexSequenceT, typename T>
	constexpr auto choose_v(T const & data) {
		return details::choose_v::impl<IndexSequenceT>::f(data);
	}
}


#define INCLUDED_MPL_CHOOSE_V_HPP
#elif !defined(INCLUDED_MPL_CHOOSE_V_HPP)
#	error circular inclusion
#endif