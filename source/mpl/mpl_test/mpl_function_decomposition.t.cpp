#include "../mpl_function_decomposition.hpp"

#include "../mpl_equals.hpp"
#include "../mpl_head.hpp"

namespace mpl_function_decomposition_test1 {
	int f();
	static_assert(mpl::EQUALS<int, mpl::function_return<decltype(f)>>, "");
}

namespace mpl_function_decomposition_test2 {
	int f(void *);
	static_assert(mpl::EQUALS<int, mpl::function_return<decltype(f)>>, "");
}

namespace mpl_function_decomposition_test3 {
	int f(void const *);
	static_assert(mpl::EQUALS<int, mpl::function_return<decltype(f)>>, "");
}

namespace mpl_function_decomposition_test4 {
	void f(int, float);
	static_assert(mpl::EQUALS<int, mpl::head<mpl::function_arguments<decltype(f)>>>, "");
}

namespace mpl_function_decomposition_test5 {
	struct s {
		int operator()(float, double) const;
	};

	static_assert(mpl::EQUALS<int, mpl::function_return<decltype(&s::operator())>>, "");
}