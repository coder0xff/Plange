#ifndef INCLUDING_MPL_FOLD_V_HPP
#define INCLUDING_MPL_FOLD_V_HPP

namespace mpl {

	namespace details::fold_v {

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
				auto next_accumulator = functor.template operator()<TAccumulator, THead>(accumulator);
				return impl<TFunctor, decltype(next_accumulator), std::tuple<TTail...>>::impl_f(functor, next_accumulator);
			}
		};

	}

	template<typename TList>
	struct fold_v {
		template<typename TFunctor, typename TInitial>
		static auto invoke(TFunctor && functor, TInitial const & initial) {
			return details::fold_v::impl<TFunctor, TInitial, TList>::impl_f(std::forward<TFunctor>(functor), initial);
		}
	};

}

#define INCLUDED_MPL_FOLD_V_HPP
#elif !defined(INCLUDED_MPL_FOLD_V_HPP)
#	error circular inclusion
#endif