#include "../mpl_first.hpp"

#include <tuple>

namespace test5 {
	template<typename T>
	struct predicate {
		static constexpr bool result = std::is_integral<T>::value;
	};

	static_assert(mpl::equals<mpl::first<predicate, std::tuple<float, int, double, char>>, int>, "");
	static_assert(mpl::equals<mpl::first<predicate, std::tuple<float, double, int, char>>, int>, "");
	static_assert(mpl::equals<mpl::first<predicate, std::tuple<float, double, char, int>>, char>, "");
}
