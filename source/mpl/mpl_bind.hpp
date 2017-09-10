#ifndef INCLUDING_MPL_BIND_HPP
#define INCLUDING_MPL_BIND_HPP
#include <tuple>

#include "mpl__if.hpp"
#include "mpl_map.hpp"
#include "mpl_apply.hpp"

namespace mpl {

	template<int ArgIndex>
	struct bind_point {
		static constexpr int arg_index = ArgIndex;
	};

	struct variadic_bind_point {}; //todo: get variadic bind working

	namespace details::bind {

		template<template <typename...> typename TMetaFunction, typename... TBindings>
		struct impl {

			template<typename... TArgs>
			struct invokation {
				template<typename T>
				struct meta_functor_impl {
					using result = T;
				};

				template<int ArgIndex>
				struct meta_functor_impl<bind_point<ArgIndex>> {
					// Does your invokation on the binding contains enough arguments?
					using result = std::tuple_element_t<ArgIndex, std::tuple<TArgs...>>;
				};

				template<typename T>
				using meta_functor = typename meta_functor_impl<T>::result;
				using mappedArguments = mpl::map<meta_functor, std::tuple<TBindings...>>;
				using result = mpl::apply<TMetaFunction, mappedArguments>;
			};

			template<typename... TArgs>
			using invoke = typename invokation<TArgs...>::result;
		};

	}

	template<template <typename...> typename TMetaFunction, typename... TBindings>
	using bind = details::bind::impl<TMetaFunction, TBindings...>;

}

#define INCLUDED_MPL_BIND_HPP
#elif !defined(INCLUDED_MPL_BIND_HPP)
#	error circular inclusion
#endif