// map_v<list<Ts...>>::map(functor) returns a tuple<Us...>, where functor has member function `template <typename T> U operator()()`.

#ifndef INCLUDING_MPL_MAP_V_HPP
#define INCLUDING_MPL_MAP_V_HPP

#include "mpl_apply.hpp"

namespace mpl {

	namespace details_map_v {
		template<typename... Ts>
		struct impl {
			template<typename TFunctor>
			static auto map(TFunctor & functor) {
				return std::make_tuple((functor.template operator() <Ts> ())...);
			}
		};
	}

	template<typename TList>
	using map_v = apply<details_map_v::impl, TList>;

}

#define INCLUDED_MPL_MAP_V_HPP
#elif !defined(INCLUDED_MPL_MAP_V_HPP)
#	error circular inclusion
#endif