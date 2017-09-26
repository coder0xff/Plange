#include "../mpl_list.hpp"

namespace test1 {
	using t = mpl::list<>;
	static_assert(t::size == 0, "wrong size");
}

namespace test2 {
	using t = mpl::list<int>;
	static_assert(t::size == 1, "wrong size");
}

namespace test3 {
	using t = mpl::list<int, float>;
	static_assert(t::size == 2, "wrong size");
}

namespace test4 {
	using t = mpl::list<int, char, float>;
	static_assert(std::is_same_v<t::get<0>, int>, "wrong type");
}

namespace test5 {
	using t = mpl::list<int, char, float>;
	static_assert(std::is_same_v<t::get<1>, char>, "wrong type");
}

namespace test6 {
	using t = mpl::list<int, char, float>;
	static_assert(std::is_same_v<t::get<2>, float>, "wrong type");
}
