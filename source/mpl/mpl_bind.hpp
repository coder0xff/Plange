#ifndef INCLUDING_MPL_BIND_HPP
#define INCLUDING_MPL_BIND_HPP
#include <tuple>

#include "mpl_any.hpp"
#include "mpl_apply.hpp"
#include "mpl_bool.hpp"
#include "mpl_drop.hpp"
#include "mpl_flatten.hpp"
#include "mpl_fold.hpp"
#include "mpl_list.hpp"
#include "mpl_map.hpp"
#include "mpl_utils.hpp"

namespace mpl {

	template<size_t ArgIndex>
	struct bind_point {
		static constexpr size_t arg_index = ArgIndex;
	};

	struct variadic_bind_point {};

	namespace details::bind {

		template<typename T>
		struct is_variadic_bind_point : false_type { };

		template<>
		struct is_variadic_bind_point<variadic_bind_point> : true_type {};
	
		//any binding element that doesn't match bind_point<Index>
		template<typename TAccumulator, typename TElement>
		struct binding_count_folder_impl {
			using result = TAccumulator;
		};

		template<size_t Accumulator, size_t Index>
		struct binding_count_folder_impl<std::integral_constant<size_t, Accumulator>, bind_point<Index>> {
			static constexpr size_t count_from_index = Index + 1;
			static constexpr size_t max = Accumulator > count_from_index ? Accumulator : count_from_index;
			using result = std::integral_constant<size_t, max>;
		};

		template<typename TAccumulator, typename TElement>
		using binding_count_folder = typename binding_count_folder_impl<TAccumulator, TElement>::result;

		// the number of required arguments
		template<typename TBindingList>
		static constexpr size_t binding_count = mpl::fold<binding_count_folder, std::integral_constant<size_t, 0>, TBindingList>::value;
		
		// substitute a bind_point or variadic_bind_point with the appropriate arguments
		template<size_t RequiredArgumentCount, typename T, typename... ArgTs>
		struct binder {
			using result = list<T>;
		};

		template<size_t RequiredArgumentCount, size_t ArgIndex, typename... ArgTs>
		struct binder<RequiredArgumentCount, bind_point<ArgIndex>, ArgTs...> {
			static_assert(ArgIndex < RequiredArgumentCount, "internal error");
			static_assert(list<ArgTs...>::size > ArgIndex, "Does your invokation contain enough arguments?");

			using result = list<typename list<ArgTs...>::template get<ArgIndex>>;
		};

		template<size_t RequiredArgumentCount, typename... ArgTs>
		struct binder<RequiredArgumentCount, variadic_bind_point, ArgTs...> {
			using result = mpl::drop<RequiredArgumentCount, list<ArgTs...>>;
		};

		template<template <typename...> typename TMetaFunction, typename TBindingList, typename TArgList>
		struct invoke_impl {
			static_assert(!std::is_same_v<TBindingList, TBindingList>, "template specialization failed");
		};

		template<template <typename...> typename TMetaFunction, typename... TBindings, typename... TArgs>
		struct invoke_impl<TMetaFunction, list<TBindings...>, list<TArgs...>> {
			using TBindingsList = list<TBindings...>;
			using TArgsList = list<TArgs...>;
			//STATIC_PRINT_TYPE(TBindingsList);
			static constexpr size_t required_argument_count = binding_count<TBindingsList>;
			//STATIC_PRINT_SIZE_T(required_argument_count);
			static constexpr size_t argument_count = TArgsList::size;
			static constexpr size_t variadic_argument_count = argument_count - required_argument_count;
			static constexpr bool has_variadic_bind_point = mpl::any<is_variadic_bind_point, TBindingsList>;

			//Does the invocation contain too many arguments?
			static_assert(variadic_argument_count == 0 || has_variadic_bind_point, "The binding must either have a variadic bind point, or there must be no extra arguments in the invocation.");

			template<typename T>
			using partially_invoked_binder = typename binder<required_argument_count, T, TArgs...>::result;
			using mappedArguments = mpl::flatten<mpl::map<partially_invoked_binder, TBindingsList>>;
			using result = mpl::apply<TMetaFunction, mappedArguments>;
		};

		template<template <typename...> typename TMetaFunction, typename TBindingList>
		struct impl {
			static_assert(!std::is_same_v<TBindingList, TBindingList>, "template substitution failed");
		};

		template<template <typename...> typename TMetaFunction, template <typename...> typename TContainer, typename... TBindings>
		struct impl<TMetaFunction, TContainer<TBindings...>> {
			template<typename... TArgs>
			using invoke = typename invoke_impl<TMetaFunction, list<TBindings...>, list<TArgs...>>::result;
		};

	}

	template<template <typename...> typename TMetaFunction, typename TBindingList>
	using bind = details::bind::impl<TMetaFunction, TBindingList>;

}

#define INCLUDED_MPL_BIND_HPP
#elif !defined(INCLUDED_MPL_BIND_HPP)
#	error circular inclusion
#endif