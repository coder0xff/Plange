#ifndef INCLUDING_MPL_SELECT_HPP
#define INCLUDING_MPL_SELECT_HPP

#include "mpl__if.hpp"
#include "mpl_equals.hpp"
#include "mpl_push.hpp"

namespace mpl {
	
	namespace details::select {
		template<template<typename> typename TMetaPredicate, typename TList>
		struct impl {};

		template<template<typename> typename TMetaPredicate, template <typename...> typename TContainer>
		struct impl<TMetaPredicate, TContainer<>> {
			using result = TContainer<>;
		};

		template<template<typename> typename TMetaPredicate, template <typename...> typename TContainer, typename THead, typename... TTail>
		struct impl<TMetaPredicate, TContainer<THead, TTail>> {
			using tail_result = typename impl<TMetaPredicate, TContainer<TTail...>>::result;
			using result = _if<equals<TMetaPredicate<THead>, std::true_type>, push<THead, tail_result>, tail_result>;
		};
	}

	template<template<typename> typename TMetaPredicate, typename TList>
	using select = typename details::select::impl<TMetaPredicate, TList>::result;

}

#define INCLUDED_MPL_SELECT_HPP
#elif !defined(INCLUDED_MPL_SELECT_HPP)
#	error circular inclusion
#endif