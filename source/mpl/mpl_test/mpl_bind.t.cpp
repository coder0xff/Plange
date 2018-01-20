#include "../mpl_bind.hpp"

#include <map>

#include "../mpl_equals.hpp"

namespace bind_details_test5 {
	using data = mpl::bind_point<5>;
	using expected = std::integral_constant<size_t, 6>;
	using actual = mpl::detail::bind::binding_count_folder_impl<std::integral_constant<size_t, 1>, data>::result;
	static_assert(mpl::EQUALS<actual, expected>, "");
}

namespace bind_details_test10 {
	using data = mpl::list<int, mpl::bind_point<0>>;
	static_assert(mpl::detail::bind::BINDING_COUNT<data> == 1, "");
}

namespace bind1 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, float>>;
	using actual = binding::invoke<>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind2 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, mpl::bind_point<0>>>;
	using actual = binding::invoke<float>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind3 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, mpl::bind_point<1>>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_4 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<1>, mpl::bind_point<0>>>;
	using actual = binding::invoke<float, int>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_5 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::variadic_bind_point>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_6 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, mpl::variadic_bind_point>>;
	using actual = binding::invoke<float>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_7 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, mpl::variadic_bind_point>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_8 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, mpl::bind_point<1>, mpl::variadic_bind_point>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_9 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, float, mpl::variadic_bind_point>>;
	using actual = binding::invoke<>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_10 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<3>, float, mpl::variadic_bind_point>>;
	using actual = binding::invoke<char, double, std::string, int>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}

namespace bind_11 {
	using expected = std::map<int, float>;
	using binding1 = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, float>>;
	using binding2 = mpl::bind<binding1::invoke, mpl::list<mpl::bind_point<0>>>;
	using actual = binding2::invoke<int>;
	static_assert(mpl::EQUALS<expected, actual>, "");
}
