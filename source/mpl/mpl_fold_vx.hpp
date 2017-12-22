//fold_vx<list<Ts...>>(Functor functor, TAccumulator initial, TArray<U> array) returns a TAccumulator, where functor has a member function `template<typename T> TAccumulator operartor()(U arrayElement const &)`.

#ifndef INCLUDING_MPL_FOLD_VX_HPP
#define INCLUDING_MPL_FOLD_VX_HPP

#include <tuple>
#include "mpl_drop_v.hpp"
#include "mpl_sfinae.hpp"
#include "mpl_equals.hpp"
#include "mpl_list.hpp"

namespace mpl {

	namespace detail::fold_vx {

		template<typename TList>
		struct impl {
			static_assert(!equals<TList, TList>, "template instantiation failed");
		};

		template<>
		struct impl<list<>> {
			template<typename TFunctor, typename TAccumulator, typename TXList>
			constexpr static TAccumulator f(TFunctor &&, TAccumulator && accumulator, TXList &&, size_t) {
				return accumulator;
			}
		};

		template<typename THead, typename... TTail>
		struct impl<list<THead, TTail...>> {
			template<typename TFunctor, typename TAccumulator, typename TXList>
			constexpr static TAccumulator f(TFunctor && functor, TAccumulator && accumulator, TXList && data, size_t index) {
				TAccumulator next_accumulator = functor.template operator()<THead>(std::forward<TAccumulator>(accumulator), data[index]);
				return impl<list<TTail...>>::template f<TFunctor, TAccumulator, TXList>(std::forward<TFunctor>(functor), std::move(next_accumulator), std::forward<TXList>(data), index + 1);
			}
		};

	}

	template<typename TList, typename TFunctor, typename TAccumulator, typename TX, size_t DataSize>
	constexpr static TAccumulator fold_vx(TFunctor const && functor, TAccumulator && initial, std::array<TX, DataSize> && data, SFINAE_PARAM(variadic_size<TList> == DataSize)) {
		return detail::fold_vx::impl<TList>::template f<TFunctor, TAccumulator, std::array<TX, DataSize>>(std::forward<TFunctor>(functor), std::forward<TAccumulator>(initial), std::forward<std::array<TX, DataSize>>(data), 0);
	}

	template<typename TList, typename TFunctor, typename TAccumulator, typename TArray>
	constexpr auto fold_vx(TFunctor && functor, TAccumulator && initial, TArray && data) {
		TAccumulator result = detail::fold_vx::impl<TList>::template f<TFunctor, TAccumulator, TArray>(std::forward<TFunctor>(functor), std::forward<TAccumulator>(initial), std::forward<TArray>(data), 0);
		return result;
	}


}

#define INCLUDED_MPL_FOLD_VX_HPP
#elif !defined(INCLUDED_MPL_FOLD_VX_HPP)
#	error circular inclusion
#endif