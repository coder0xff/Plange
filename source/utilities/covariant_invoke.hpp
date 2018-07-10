#ifndef INCLUDED_UTILITIES_COVARIANT_INVOKE_HPP
#define INCLUDED_UTILITIES_COVARIANT_INVOKE_HPP

#include "mpl_equals.hpp"
#include "mpl_function_decomposition.hpp"
#include "mpl_head.hpp"
#include "mpl_is_const.hpp"
#include "mpl_sfinae.hpp"
#include "mpl_utils.hpp"

namespace detail {
	template <typename T>
	struct invoke_type {
		typedef mpl::decay<mpl::head<mpl::function_arguments<decltype(&T::operator ())>>> in_t;
		typedef mpl::function_return<decltype(&T::operator ())> out_t;
	};
}

template<typename U, typename T, typename V1, SFINAE_OVERLOAD(!mpl::EQUALS<U, void>)>
U covariant_invoke(T const & value, V1 const & func1) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	auto const * asU1 = dynamic_cast<in_t const *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	throw std::runtime_error("no suitable dispatch function");
}

template<typename U, typename T, typename V1, typename V2, typename... Vs, SFINAE_OVERLOAD(!mpl::EQUALS<U, void>)>
U covariant_invoke(T const & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	auto const * asU1 = dynamic_cast<in_t const *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	return covariant_invoke<U>(value, func2, funcs...);
}

template<typename U, typename T, typename V1, SFINAE_OVERLOAD(mpl::EQUALS<U, void>)>
void covariant_invoke(T const & value, V1 const & func1) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	static_assert(std::is_same<typename detail::invoke_type<V1>::out_t, void>::value, "function does not return void");
	auto const * asU1 = dynamic_cast<in_t const *>(&value);
	if (asU1 != nullptr) {
		func1(*asU1);
		return;
	}
	throw std::runtime_error("no suitable dispatch function");
}

template<typename U, typename T, typename V1, typename V2, typename... Vs, SFINAE_OVERLOAD(mpl::EQUALS<U, void>)>
void covariant_invoke(T const & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	static_assert(std::is_same<typename detail::invoke_type<V1>::out_t, void>::value, "function does not return void");
	auto const * asU1 = dynamic_cast<in_t const *>(&value);
	if (asU1 != nullptr) {
		func1(*asU1);
		return;
	}
	covariant_invoke<U>(value, func2, funcs...);
}

template<typename U, typename T, typename V1, SFINAE_OVERLOAD(!mpl::EQUALS<U, void> && !mpl::IS_CONST<T>)>
U covariant_invoke(T & value, V1 const & func1) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	auto * asU1 = dynamic_cast<in_t *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	throw std::runtime_error("no suitable dispatch function");
}

template<typename U, typename T, typename V1, typename V2, typename... Vs, SFINAE_OVERLOAD(!mpl::EQUALS<U, void> && !mpl::IS_CONST<T>)>
U covariant_invoke(T & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	auto * asU1 = dynamic_cast<in_t *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	return covariant_invoke<U>(value, func2, funcs...);
}

template<typename U, typename T, typename V1, SFINAE_OVERLOAD(mpl::EQUALS<U, void> && !mpl::IS_CONST<T>)>
void covariant_invoke(T & value, V1 const & func1) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	static_assert(std::is_same<typename detail::invoke_type<V1>::out_t, void>::value, "function does not return void");
	auto * asU1 = dynamic_cast<in_t *>(&value);
	if (asU1 != nullptr) {
		func1(*asU1);
		return;
	}
	throw std::runtime_error("no suitable dispatch function");
}
template<typename U, typename T, typename V1, typename V2, typename... Vs, SFINAE_OVERLOAD(mpl::EQUALS<U, void> && !mpl::IS_CONST<T>)>
void covariant_invoke(T & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename detail::invoke_type<V1>::in_t in_t;
	static_assert(std::is_same<typename detail::invoke_type<V1>::out_t, void>::value, "function does not return void");
	auto * asU1 = dynamic_cast<in_t *>(&value);
	if (asU1 != nullptr) {
		func1(*asU1);
		return;
	}
	covariant_invoke<U>(value, func2, funcs...);
}

#endif // INCLUDED_UTILITIES_COVARIANT_INVOKE_HPP
