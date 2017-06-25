#ifndef UTILITIES_DYNAMIC_DISPATCH_HPP
#define UTILITIES_DYNAMIC_DISPATCH_HPP

#include <functional>

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

template<typename U, typename T, typename V1>
U dynamic_dispatch(T const & value, V1 const & func1) {
	typedef typename details::invoke_type<V1>::type type;
	auto const * asU1 = dynamic_cast<type const *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	throw std::runtime_error("no suitable dispatch function");
}

template<typename U, typename T, typename V1, typename V2, typename... Vs>
U dynamic_dispatch(T const & value, V1 const & func1, V2 const & func2, Vs const &... funcs) {
	typedef typename details::invoke_type<V1>::type type;
	auto const * asU1 = dynamic_cast<type const *>(&value);
	if (asU1 != nullptr) {
		return func1(*asU1);
	}
	return dynamic_dispatch<U>(value, func2, funcs...);
}


#endif //UTILITIES_DYNAMIC_DISPATCH_HPP