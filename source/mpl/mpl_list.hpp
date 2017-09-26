#ifndef INCLUDING_MPL_LIST_HPP
#define INCLUDING_MPL_LIST_HPP

// The metafunctions in this library work well with std::tuple.
// However, mpl::list provides a zero-sized struct

#include <tuple>

namespace mpl {

	template<typename... Ts>
	struct list {
		static constexpr size_t size = std::tuple_size_v<std::tuple<Ts...>>;
		
		template<size_t Index>
		using get = std::tuple_element_t<Index, std::tuple<Ts...>>;
	};

}

#define INCLUDED_MPL_LIST_HPP
#elif !defined(INCLUDED_MPL_LIST_HPP)
#	error circular inclusion
#endif