#ifndef INCLUDING_MPL_PUSH_HPP
#define INCLUDING_MPL_PUSH_HPP

namespace mpl {
	namespace details_push {

		template<typename TElement, typename TList>
		struct impl {};

		template<typename TElement, template <typename...> typename TList, typename... TListElements>
		struct impl<TElement, TList<TListElements...>> {
			using result = TList<TElement, TListElements...>;
		};

	}

template<typename TElement, typename TList>
using push = typename details_push::impl<TElement, TList>::result;

}

#define INCLUDED_MPL_PUSH_HPP
#elif !defined(INCLUDED_MPL_PUSH_HPP)
#	error circular inclusion
#endif