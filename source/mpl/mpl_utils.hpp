#ifndef INCLUDED_MPL_UTILS_HPP
#define INCLUDED_MPL_UTILS_HPP

#define STATIC_PRINT_TYPE(x) using mpl_print_as_error = typename mpl::print_as_error<x>::print
#define STATIC_PRINT_SIZE_T(x) using mpl_print_as_error = typename mpl::print_as_error<std::integral_constant<size_t, x>>::print

namespace mpl {

	namespace detail::variadic_size {
		template<typename TList>
		struct impl {};

		template<template<typename...> typename TContainer, typename... Ts>
		struct impl<TContainer<Ts...>> {
			constexpr static size_t result = sizeof...(Ts);
		};
	}

	template<typename TList>
	constexpr size_t VARIADIC_SIZE = detail::variadic_size::impl<TList>::result;

	template<typename T>
	struct print_as_error {
	};

	template<typename T>
	using decay = typename std::decay<T>::type;
}

namespace std {
	namespace detail {
		template<class> struct is_ref_wrapper : false_type {};
		template<class T> struct is_ref_wrapper<reference_wrapper<T>> : true_type {};

		template<class T>
		using not_ref_wrapper = negation<is_ref_wrapper<decay_t<T>>>;

		template <class D, class...> struct return_type_helper { using type = D; };
		template <class... Types>
		struct return_type_helper<void, Types...> : common_type<Types...> {
			static_assert(conjunction_v<not_ref_wrapper<Types>...>,
				"Types cannot contain reference_wrappers when D is void");
		};

		template <class D, class... Types>
		using return_type = array<typename return_type_helper<D, Types...>::type,
			sizeof...(Types)>;
	}

	template < class D = void, class... Types>
	constexpr detail::return_type<D, Types...> make_array(Types&&... t) {
		return { std::forward<Types>(t)... };
	}
}

#endif //INCLUDED_MPL_UTILS_HPP