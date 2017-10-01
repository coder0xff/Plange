#ifndef INCLUDED_MPL_UTILS_HPP
#define INCLUDED_MPL_UTILS_HPP
#include <tuple>

#define STATIC_PRINT_TYPE(x) using mpl_print_as_error = typename mpl::print_as_error<x>::print
#define STATIC_PRINT_SIZE_T(x) using mpl_print_as_error = typename mpl::print_as_error<std::integral_constant<size_t, x>>::print

namespace mpl {

	namespace details::variadic_size {
		template<typename TList>
		struct impl {};

		template<template<typename...> typename TContainer, typename... Ts>
		struct impl<TContainer<Ts...>> {
			constexpr static size_t result = sizeof...(Ts);
		};
	}

	template<typename TList>
	constexpr size_t variadic_size = details::variadic_size::impl<TList>::result;

	template<typename T>
	struct print_as_error {
	};
}

namespace std {
	namespace details {
		template<class> struct is_ref_wrapper : std::false_type {};
		template<class T> struct is_ref_wrapper<std::reference_wrapper<T>> : std::true_type {};

		template<class T>
		using not_ref_wrapper = std::negation<is_ref_wrapper<std::decay_t<T>>>;

		template <class D, class...> struct return_type_helper { using type = D; };
		template <class... Types>
		struct return_type_helper<void, Types...> : std::common_type<Types...> {
			static_assert(conjunction_v<not_ref_wrapper<Types>...>,
				"Types cannot contain reference_wrappers when D is void");
		};

		template <class D, class... Types>
		using return_type = std::array<typename return_type_helper<D, Types...>::type,
			sizeof...(Types)>;
	}

	template < class D = void, class... Types>
	constexpr details::return_type<D, Types...> make_array(Types&&... t) {
		return { std::forward<Types>(t)... };
	}
}

#endif //INCLUDED_MPL_UTILS_HPP