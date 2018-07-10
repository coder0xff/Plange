#ifndef INCLUDING_MPL_FOLD_VV_HPP
#define INCLUDING_MPL_FOLD_VV_HPP

#include <tuple>

#include "mpl_drop_v.hpp"

namespace mpl {

	namespace detail::fold_vv {

		template<typename TFunctor, typename TAccumulator, typename TList>
		struct impl {	};

		template<typename TFunctor, typename TAccumulator>
		struct impl<TFunctor, TAccumulator, std::tuple<>> {
			static auto impl_f(TFunctor const &, TAccumulator accumulator, std::tuple<> const & values) {
				return accumulator;
			}
		};

		template<typename TFunctor, typename TAccumulator, typename THead, typename... TTail>
		struct impl<TFunctor, TAccumulator, std::tuple<THead, TTail...>> {
			static auto impl_f(TFunctor & functor, TAccumulator accumulator, std::tuple<THead, TTail...> const & values) {
				auto nextAccumulator = functor.template operator()<THead>(accumulator, std::get<0>(values));
				auto nextValues = mpl::drop_v<1>(values);
				return impl<TFunctor, decltype(nextAccumulator), std::tuple<TTail...>>::impl_f(functor, nextAccumulator, nextValues);
			}
		};

	}

	template<typename TFunctor, typename TAccumulator, typename... Ts>
	constexpr TAccumulator fold_vv(TFunctor && functor, TAccumulator initial, std::tuple<Ts...> const & list) {
		return detail::fold_vv::impl<TFunctor, TAccumulator, std::tuple<Ts...>>::impl_f(std::forward<TFunctor>(functor), initial, list);
	}

}

#define INCLUDED_MPL_FOLD_VV_HPP
#elif !defined(INCLUDED_MPL_FOLD_VV_HPP)
#	error circular inclusion
#endif