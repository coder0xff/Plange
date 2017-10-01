#include "../mpl_function_decomposition.hpp"
#include "../mpl_equals.hpp"

int f();

static_assert(mpl::equals<int, mpl::function_return<decltype(f)>>, "");