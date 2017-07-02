#ifndef UTILITIES_COVARIANT_INVOKE_HPP
#define UTILITIES_COVARIANT_INVOKE_HPP

namespace details {
	template <typename T>
	struct invoke_type_impl {
		static_assert(!std::is_same_v<T, T>, "template instantiation failed");
	};

	template <typename T, typename U, typename V>
	struct invoke_type_impl<T (U::*)(V const &) const> {
		typedef V type;
	};

	template <typename T>
	struct invoke_type {
		typedef typename invoke_type_impl<decltype(&T::operator ())>::type type;
	};
}

template<typename U, typename T, typename V1, typename std::enable_if<!std::is_same<U, void>::value, int>::type = 0>
U covariant_invoke(T const & value, V1 const & func1) {
	typedef typename details::invoke_type<V1>::type type;
	auto const * asU1 = dynamic_cast<type const *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	throw std::runtime_error("no suitable dispatch function");
}

template<typename U, typename T, typename V1, typename V2, typename... Vs, typename std::enable_if<!std::is_same<U, void>::value, int>::type = 0>
U covariant_invoke(T const & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename details::invoke_type<V1>::type type;
	auto const * asU1 = dynamic_cast<type const *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	return covariant_invoke<U>(value, func2, funcs...);
}

template<typename U, typename T, typename V1, typename std::enable_if<std::is_same<U, void>::value, int>::type = 0>
void covariant_invoke(T const & value, V1 const & func1) {
	typedef typename details::invoke_type<V1>::type type;
	auto const * asU1 = dynamic_cast<type const *>(&value);
	if (asU1 != nullptr) {
		func1(*asU1);
	}
	throw std::runtime_error("no suitable dispatch function");
}

template<typename U, typename T, typename V1, typename V2, typename... Vs, typename std::enable_if<std::is_same<U, void>::value, int>::type = 0>
void covariant_invoke(T const & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename details::invoke_type<V1>::type type;
	auto const * asU1 = dynamic_cast<type const *>(&value);
	if (asU1 != nullptr) {
		func1(*asU1);
	}
	covariant_invoke<U>(value, func2, funcs...);
}

#endif //UTILITIES_COVARIANT_INVOKE_HPP