#include "../mpl_head.hpp"

#include "../mpl_equals.hpp"
#include "../mpl_list.hpp"

static_assert(mpl::EQUALS<int, mpl::head<mpl::list<int, float>>>, "");

