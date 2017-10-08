#include "../mpl_equals.hpp"
#include "../mpl_head.hpp"
#include "../mpl_list.hpp"

static_assert(mpl::equals<int, mpl::head<mpl::list<int, float>>>, "");

