#include "../mpl_equals.hpp"

#include <map>
#include <tuple>

#include "../mpl_apply.hpp"
#include "../mpl_fold.hpp"
#include "../mpl_fold_i.hpp"

static_assert(!mpl::EQUALS<int, float>, "");

static_assert(mpl::EQUALS<std::map<int, float>, mpl::apply<std::map, std::tuple<int, float>>>, "");

namespace test1 {
	template <typename T, typename U>
	struct test_impl {};

	template <int V, typename U>
	struct test_impl<std::integral_constant<int, V>, U> {
		using result = std::integral_constant<int, V + sizeof(U)>;
	};

	template <typename T, typename U>
	using test = typename test_impl<T, U>::result;

	using result = mpl::fold<test, std::integral_constant<int, 0>, std::tuple<float, char>>;
	static_assert(mpl::EQUALS<result, std::integral_constant<int, 5>>, "");
}

namespace test2 {
	template <typename T, size_t Index, typename U>
	struct test_impl {};

	template <int V, size_t Index, typename U>
	struct test_impl<std::integral_constant<int, V>, Index, U> {
		using result = std::integral_constant<int, V + sizeof(U) + Index>;
	};

	template <typename T, size_t Index, typename U>
	using test = typename test_impl<T, Index, U>::result;

	using result = mpl::fold_i<test, std::integral_constant<int, 0>, std::tuple<float, char>>;
	static_assert(mpl::EQUALS<result, std::integral_constant<int, 6>>, "");
}
