#ifndef INCLUDING_MPL_FOLD_VALUE_HPP
#define INCLUDING_MPL_FOLD_VALUE_HPP

namespace mpl {

	namespace details_fold_value {

		template<typename TFunctor, typename TAccumulator>
		TAccumulator impl(TFunctor & functor, TAccumulator accumulator) {
			return accumulator;
		}

		template<typename TFunctor, typename TAccumulator, typename TListHead, typename... TListTail>
		TAccumulator impl(TFunctor & functor, TAccumulator accumulator) {
			return impl<TFunctor, TAccumulator, TListTail...>(functor, functor.template operator()<TListHead>(accumulator));
		}

		template<typename TFunctor, typename TAccumulator>
		TAccumulator impl(TFunctor const & functor, TAccumulator accumulator) {
			return accumulator;
		}

		template<typename TFunctor, typename TAccumulator, typename TListHead, typename... TListTail>
		TAccumulator impl(TFunctor const & functor, TAccumulator accumulator) {
			return impl<TFunctor, TAccumulator, TListTail...>(functor, functor.template operator()<TListHead>(accumulator));
		}
	}

	template<typename... Ts>
	struct fold_value {
		template<typename TFunctor, typename T>
		T fold(TFunctor && functor, T const & initial) {
			return details_fold_value::impl<TFunctor, T, Ts...>(std::forward<TFunctor>(functor), initial);
		}
	};

}

#define INCLUDED_MPL_FOLD_VALUE_HPP
#elif !defined(INCLUDED_MPL_FOLD_VALUE_HPP)
#	error circular inclusion
#endif