//fold_vx<list<Ts...>>(Functor functor, TAccumulator initial, TArray<U> array) returns a TAccumulator, where functor has a member function `template<typename T> TAccumulator operartor()(U arrayElement const &)`.

#ifndef INCLUDING_MPL_FOLD_VX_HPP
#define INCLUDING_MPL_FOLD_VX_HPP

#include "mpl_drop_v.hpp"
#include "mpl_sfinae.hpp"
#include "mpl_equals.hpp"
#include "mpl_list.hpp"

namespace mpl {

	namespace detail::fold_vx {

		template<typename TList>
		struct impl {
			static_assert(!EQUALS<TList, TList>, "template instantiation failed");
		};

		template<>
		struct impl<list<>> {
			template<typename TFunctor, typename TAccumulator, typename TxList>
			constexpr static std::remove_reference_t<TAccumulator> f(TFunctor &&, TAccumulator && accumulator, TxList &&, size_t) {
				return accumulator;
			}
		};

		template<typename THead, typename... TTail>
		struct impl<list<THead, TTail...>> {
			template<typename TFunctor, typename TAccumulator, typename TxList>
			constexpr static std::remove_reference_t<TAccumulator> f(TFunctor && functor, TAccumulator && accumulator, TxList && data, size_t const index) {
				auto nextAccumulator = functor.template operator()<THead>(std::forward<TAccumulator>(accumulator), data[index]);
				return impl<list<TTail...>>::template f<TFunctor, TAccumulator, TxList>(std::forward<TFunctor>(functor), std::move(nextAccumulator), std::forward<TxList>(data), index + 1);
			}
		};

	}

	template<typename TList, typename TFunctor, typename TAccumulator, typename Tx, size_t DataSize>
	constexpr static std::remove_reference_t<TAccumulator> fold_vx(TFunctor const && functor, TAccumulator && initial, std::array<Tx, DataSize> && data, SFINAE_PARAM(VARIADIC_SIZE<TList> == DataSize)) {
		return detail::fold_vx::impl<TList>::template f<TFunctor, TAccumulator, std::array<Tx, DataSize>>(std::forward<TFunctor>(functor), std::forward<TAccumulator>(initial), std::forward<std::array<Tx, DataSize>>(data), 0);
	}

	template<typename TList, typename TFunctor, typename TAccumulator, typename TArray>
	constexpr auto fold_vx(TFunctor && functor, TAccumulator && initial, TArray && data) {
		std::remove_reference_t<TAccumulator> result = detail::fold_vx::impl<TList>::template f<TFunctor, TAccumulator, TArray>(std::forward<TFunctor>(functor), std::forward<TAccumulator>(initial), std::forward<TArray>(data), 0);
		return result;
	}


}

#define INCLUDED_MPL_FOLD_VX_HPP
#elif !defined(INCLUDED_MPL_FOLD_VX_HPP)
#	error circular inclusion
#endif