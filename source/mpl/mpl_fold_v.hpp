#ifndef INCLUDING_MPL_FOLD_V_HPP
#define INCLUDING_MPL_FOLD_V_HPP

#include <tuple>

namespace mpl {

	namespace detail::fold_v {

		template<typename TFunctor, typename TAccumulator, typename TList>
		struct impl {	};

		template<typename TFunctor, typename TAccumulator, template <typename...> typename TContainer>
		struct impl<TFunctor, TAccumulator, TContainer<>> {
			static auto impl_f(TFunctor const &, TAccumulator accumulator) {
				return accumulator;
			}
		};

		template<typename TFunctor, typename TAccumulator, template <typename...> typename TContainer, typename THead, typename... TTail>
		struct impl<TFunctor, TAccumulator, TContainer<THead, TTail...>> {
			static auto impl_f(TFunctor & functor, TAccumulator accumulator) {
				auto nextAccumulator = functor.template operator()<TAccumulator, THead>(accumulator);
				return impl<TFunctor, decltype(nextAccumulator), std::tuple<TTail...>>::impl_f(functor, nextAccumulator);
			}
		};

	}

	template<typename TList>
	struct fold_v {
		//TFunctor::operator() : (TInitial initial) * TElement -> (TResult result)
		//Note that TResult may not be the same as TInitial, because we are also folding over types.
		template<typename TFunctor, typename TInitial>
		static auto invoke(TFunctor && functor, TInitial && initial) {
			return detail::fold_v::impl<TFunctor, TInitial, TList>::impl_f(std::forward<TFunctor>(functor), std::forward<TInitial>(initial));
		}
	};

}

#define INCLUDED_MPL_FOLD_V_HPP
#elif !defined(INCLUDED_MPL_FOLD_V_HPP)
#	error circular inclusion
#endif