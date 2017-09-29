#include "../mpl_bind.hpp"

#include <map>

#include "../mpl_equals.hpp"

namespace test1 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, float>>;
	using actual = binding::invoke<>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test2 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, mpl::bind_point<0>>>;
	using actual = binding::invoke<float>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test3 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, mpl::bind_point<1>>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test4 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<1>, mpl::bind_point<0>>>;
	using actual = binding::invoke<float, int>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test5 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::variadic_bind_point>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test6 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, mpl::variadic_bind_point>>;
	using actual = binding::invoke<float>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test7 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, mpl::variadic_bind_point>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test8 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, mpl::bind_point<1>, mpl::variadic_bind_point>>;
	using actual = binding::invoke<int, float>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test9 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<int, float, mpl::variadic_bind_point>>;
	using actual = binding::invoke<>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test10 {
	using expected = std::map<int, float>;
	using binding = mpl::bind<std::map, mpl::list<mpl::bind_point<3>, float, mpl::variadic_bind_point>>;
	using actual = binding::invoke<char, double, std::string, int>;
	static_assert(mpl::equals<expected, actual>, "");
}

namespace test11 {
	using expected = std::map<int, float>;
	using binding1 = mpl::bind<std::map, mpl::list<mpl::bind_point<0>, float>>;
	using binding2 = mpl::bind<binding1::invoke, mpl::list<mpl::bind_point<0>>>;
	using actual = binding2::invoke<int>;
	static_assert(mpl::equals<expected, actual>, "");
}