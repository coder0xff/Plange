#ifndef INCLUDING_MPL_FIRST_HPP
#define INCLUDING_MPL_FIRST_HPP

namespace mpl {

	namespace details::first {

		template<typename TMetaPredicate>
		struct fold_metafunction {

			template<typename TAccumulator, typename TElement>
			struct impl {
				using result = _if<equals<TAccumulator, none>, _if<TMetaPredicate<TElement>::result, some<TElement>, none>, TAccumulator>;
			};

		};
	}

	template<template<typename> typename TMetaPredicate, typename TList>
	using first = fold<details::first::fold_metafunction<TMetaPredicate>::impl, TList>::type;
}

#define INCLUDED_MPL_FIRST_HPP
#elif !defined(INCLUDED_MPL_FIRST_HPP)
#	error circular inclusion
#endif