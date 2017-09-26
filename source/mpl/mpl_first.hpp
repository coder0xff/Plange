#ifndef INCLUDING_MPL_FIRST_HPP
#define INCLUDING_MPL_FIRST_HPP

#include "mpl__if.hpp"
#include "mpl_equals.hpp"
#include "mpl_fold.hpp"
#include "mpl_none.hpp"
#include "mpl_some.hpp"

namespace mpl {

	namespace details::first {

		template<template<typename> typename TMetaPredicate>
		struct fold_metafunction {

			template<typename TAccumulator, typename TElement>
			using result = _if<equals<TAccumulator, none>, _if<TMetaPredicate<TElement>::result, some<TElement>, none>, TAccumulator>;

		};
	}

	template<template<typename> typename TMetaPredicate, typename TList>
	using first = typename fold<details::first::fold_metafunction<TMetaPredicate>::template result, none, TList>::type;
}

#define INCLUDED_MPL_FIRST_HPP
#elif !defined(INCLUDED_MPL_FIRST_HPP)
#	error circular inclusion
#endif